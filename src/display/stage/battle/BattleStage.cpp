//
// Created by Ethan Pedrick on 4/5/2026.
// edited by Brittney Moore on 4/15/2026

#include "BattleStage.h"
#include "WindowManager.h"
#include "display/stage/Stage.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Mouse.hpp>
#include <format>
#include <iostream>
#include <memory>
#include <vector>
#include <filesystem>

#include "game/combat/deck/DeckManager.h"
#include "game/entity/enemy/Enemy.h"
#include "game/entity/player/PlayerCharacter.h"


BattleStage::BattleStage(std::unique_ptr<CombatSequence> sequence)
    : Stage(),
      m_sequence{std::move(sequence)},
      m_selectedCard{-1},
        m_playerHovered(false),
      m_hoveredEnemy{nullptr},
      m_allEnemiesDead{false},
      m_playerDead{false},
      m_cardsPlayed{0},
      m_drawCounterText(WindowManager::getFont()),
      m_wasMousePressed{false},
      m_menuButton{"Menu", {600.f, 40.f}, {120.f, 50.f}},
      m_exitButton{"Exit", {600.f, 100.f}, {120.f, 50.f}},
      m_discardButton {"Discard", {600.f, 450.f}, {120.f, 50.f}},
      m_passButton {"Pass", {400.f, 520.f}, {120.f, 50.f}},
      m_menuOpen{false}
{
    m_sequence->getPlayer()->getDeck().activateCards(8);
    m_drawCounterText.setFont(WindowManager::getFont());
    m_drawCounterText.setCharacterSize(20);
    m_drawCounterText.setFillColor(sf::Color::White);
    m_drawCounterText.setPosition({10.f, 10.f});
    updateDrawCounterDisplay();
    m_backgroundTexture.emplace();
if (!m_backgroundTexture->loadFromFile("assets/sprites/battle_background.jpg"))
{
    std::cerr << "Failed to load battle_background.jpg\n";
}
else
{
    m_backgroundSprite.emplace(*m_backgroundTexture);

    sf::RenderWindow& window = WindowManager::getWindow();
    const auto bgSize = m_backgroundSprite->getGlobalBounds().size;

    m_backgroundSprite->setScale({
        static_cast<float>(window.getSize().x) / bgSize.x,
        static_cast<float>(window.getSize().y) / bgSize.y
    });
}
//m_trashTexture.emplace();

// List of places to look for the trash sprite
/*trouble shoot with later this works

std::vector<std::string> pathsToTry = {
    "dependencies/sprites/Trash.png",
    "assets/sprites/Trash.png",
    "sprites/Trash.png",
    "Trash.png"
};
*/

// Try each path until we find the file
//finding file for trash try this works for troubleshooting late
/* bool found = false;
for (const auto& path : pathsToTry) {
    if (m_trashTexture->loadFromFile(path)) {
        m_trashSprite.emplace(*m_trashTexture);
        m_trashSprite->setPosition({750.f, 550.f});
        m_trashSprite->setScale({0.25f, 0.25f});
        std::cerr << "Successfully loaded Trash.png from: " << path << "\n";
        found = true;
        break;
    }
}

if (!found) {
    std::cerr << "Failed to load Trash.png from any location\n";
}
*/
    std::cout << "BattleStage initialized\n";
}



void BattleStage::update() {
    sf::RenderWindow& window = WindowManager::getWindow();
if (m_backgroundSprite.has_value())
{
    window.draw(*m_backgroundSprite);
}
  m_menuButton.update();

if (m_menuButton.hasBeenClicked())
{
    m_menuOpen = !m_menuOpen;
}
if (m_menuOpen) {
    m_exitButton.update();


    // click logic
    if (m_exitButton.hasBeenClicked()) {
        window.close();
        return;
    }
}

    bool mouseCurrentlyPressed = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
    bool mouseJustPressed = mouseCurrentlyPressed && !m_wasMousePressed;
    m_wasMousePressed = mouseCurrentlyPressed;

m_discardButton.update();
if (m_discardButton.hasBeenClicked()) {
    std::cout << "Discard button clicked at position 600, 450!\n";
    if (m_selectedCard != -1) {
        m_selectedCard = -1;
        mouseJustPressed = false;  //hopefully prevent card from reselecting 
}
}


m_sequence->getPlayer()->draw();

    // basically should combat continue

    m_sequence->update();

    switch (m_sequence->getState()) {
        case PLAYER_LOST: {

            m_drawCounterText.setString("You lose!");
            window.draw(m_drawCounterText);

            return;
        }

        case PLAYER_WON: {

            m_drawCounterText.setString("You win!");
            window.draw(m_drawCounterText);

            return;
        }

        default: break;
    }



    sf::Text playerNameText(WindowManager::getFont());
    playerNameText.setCharacterSize(18);
    playerNameText.setFillColor(sf::Color::White);
    playerNameText.setString(
        m_sequence->getPlayer()->getName() + " HP: " +
        std::to_string(static_cast<int>(m_sequence->getPlayer()->getHealthPool().getCurrentHealth()))
    );
    playerNameText.setPosition({
        m_sequence->getPlayer()->getSprite().getPosition().x - 45.f,
        m_sequence->getPlayer()->getSprite().getPosition().y - 95.f
    });
    window.draw(playerNameText);

    for (const auto& enemy : m_sequence->getEnemies()) {
        sf::Text enemyNameText(WindowManager::getFont());
        enemyNameText.setCharacterSize(18);
        enemyNameText.setFillColor(sf::Color::White);
        enemyNameText.setString(
            enemy->getName() + " HP: " +
            std::to_string(static_cast<int>(enemy->getHealthPool().getCurrentHealth()))
        );
        enemyNameText.setPosition({
            enemy->getSprite().getPosition().x - 45.f,
            enemy->getSprite().getPosition().y - 95.f
        });
        window.draw(enemyNameText);
    }


    for (const auto& enemy : m_sequence->getEnemies()) {
        if (!enemy->getHealthPool().isDead()) enemy->draw();
    }

    // there is probably some way to move some of the card logic out of here but i'm not sure how rn

    std::vector<std::shared_ptr<Card>>& cards = m_sequence->getPlayer()->getDeck().getCards();

    //for the trash can 
    /* trouble shoot with later 
    if (m_trashSprite.has_value())
    {
        window.draw(*m_trashSprite);
    }
    */
    for (int i = 0; i < static_cast<int>(cards.size()); ++i) {
        std::shared_ptr<Card> card = cards.at(i);

        if (card->isHovered() && m_selectedCard == -1) {
            if (mouseJustPressed) {
                m_selectedCard = i;
            }
        }

        if (m_selectedCard == i) {

            sf::Vector2f mousePos = WindowManager::getMousePos();

            card->drawFloating(mousePos);

            if (isCharacterHovered() && mouseJustPressed) {

                bool cardUsed = false;

                if (m_playerHovered) {
                    cardUsed = card->use(*m_sequence->getPlayer(), *m_sequence->getPlayer());
                }

                else if (m_hoveredEnemy != nullptr) {
                    cardUsed = card->use(*m_sequence->getPlayer(), *m_hoveredEnemy);
                }

                if (cardUsed) {

                    m_selectedCard = -1;

                    m_sequence->getPlayer()->getDeck().deactivateCard(card);

                    m_cardsPlayed += 1;

                    if (m_cardsPlayed % 3 == 0) {
                        refreshHand();
                        m_selectedCard = -1;
                        for (auto& enemy : m_sequence->getEnemies()) {
                            enemy->attack(*m_sequence->getPlayer());
                        }
                    }
                    updateDrawCounterDisplay();

                }

                break;
            }
        } else {
            card->draw(i, cards.size());
        }
    }
sf::Text statsText(WindowManager::getFont());
statsText.setCharacterSize(18);
statsText.setFillColor(sf::Color::White);
statsText.setPosition({10.f, 40.f});
statsText.setString(
    "Stats\nHP: " + std::to_string(static_cast<int>(m_sequence->getPlayer()->getHealthPool().getCurrentHealth())) +
    "\nBlock: " + std::to_string(static_cast<int>(m_sequence->getPlayer()->getHealthPool().getBlock()))
);
window.draw(statsText);

    window.draw(m_drawCounterText);
}

bool BattleStage::isCharacterHovered() {
    sf::Vector2f mousePos = WindowManager::getMousePos();
  m_hoveredEnemy = nullptr;
  m_playerHovered = false;

    for (std::unique_ptr<Enemy>& enemy : m_sequence->getEnemies()) {
        if (enemy->getSprite().getGlobalBounds().contains(mousePos)) {
            m_hoveredEnemy = enemy.get();
            m_playerHovered = false;
            return true;
        }
    }

    if (m_sequence->getPlayer()->getSprite().getGlobalBounds().contains(mousePos)) {
        m_playerHovered = true;
        return true;
    } else {
        m_playerHovered = false;
    }
    return false;
}

void BattleStage::updateDrawCounterDisplay() {
    int remaining = 3 - (m_cardsPlayed % 3);
    m_drawCounterText.setString("actions left: " + std::to_string(remaining));
}

void BattleStage::refreshHand() {
    std::vector<std::shared_ptr<Card>> active = m_sequence->getPlayer()->getDeck().getCards();
    for (auto& card : active) {
        m_sequence->getPlayer()->getDeck().deactivateCard(card);
    }

    if (m_sequence->getPlayer()->getDeck().getInactiveCount() < 8) {
        m_sequence->getPlayer()->getDeck().reshuffleDiscard();
    }

    m_sequence->getPlayer()->getDeck().activateCards(8);
}

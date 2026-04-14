//
// Created by Ethan Pedrick on 4/5/2026.
//

#include "BattleStage.h"
#include "WindowManager.h"
#include "display/stage/Stage.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Mouse.hpp>
#include <format>
#include <iostream>
#include <memory>
#include <vector>

#include "game/combat/deck/DeckManager.h"
#include "game/entity/enemy/Enemy.h"
#include "game/entity/player/PlayerCharacter.h"


BattleStage::BattleStage(std::unique_ptr<CombatSequence> sequence)
    : Stage(),
      m_sequence{std::move(sequence)},
      m_selectedCard{-1},
      m_hoveredEnemy{nullptr},
      m_allEnemiesDead{false},
      m_playerDead{false},
      m_cardsPlayed{0},
      m_drawCounterText(WindowManager::getFont()),
      m_wasMousePressed{false}
{
    m_sequence->getPlayer()->getDeck().activateCards(8);
    m_drawCounterText.setFont(WindowManager::getFont());
    m_drawCounterText.setCharacterSize(20);
    m_drawCounterText.setFillColor(sf::Color::White);
    m_drawCounterText.setPosition({10.f, 10.f});
    updateDrawCounterDisplay();

    std::cout << "BattleStage initialized\n";
}

void BattleStage::update() {
    sf::RenderWindow& window = WindowManager::getWindow();


    // click logic
    bool mouseCurrentlyPressed = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
    bool mouseJustPressed = mouseCurrentlyPressed && !m_wasMousePressed;
    m_wasMousePressed = mouseCurrentlyPressed;
    
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

    for (const auto& enemy : m_sequence->getEnemies()) {
        if (!enemy->getHealthPool().isDead()) enemy->draw();
    }

    // there is probably some way to move some of the card logic out of here but i'm not sure how rn

    std::vector<std::shared_ptr<Card>>& cards = m_sequence->getPlayer()->getDeck().getCards();

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

                if (m_playerHovered)
                    card->use(*m_sequence->getPlayer(), *m_sequence->getPlayer());
                else if (m_hoveredEnemy != nullptr) card->use(*m_sequence->getPlayer(), *m_hoveredEnemy);

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

                break;
            }
        } else {
            card->draw(i, cards.size());
        }
    }

    window.draw(m_drawCounterText);
}

bool BattleStage::isCharacterHovered() {
    sf::Vector2f mousePos = WindowManager::getMousePos();
  m_hoveredEnemy = nullptr;
  m_playerHovered = false;

    for (std::unique_ptr<Enemy>& enemy : m_sequence->getEnemies()) {
        if (enemy->getSprite().getGlobalBounds().contains(mousePos)) {
            m_hoveredEnemy = enemy.get();
            m_playerHovered = false;;
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

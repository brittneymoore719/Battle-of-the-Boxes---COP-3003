//
// Created by Ethan Pedrick on 4/5/2026.
//

#include "BattleStage.h"
#include "WindowManager.h"
#include "deck/DeckManager.h"
#include "display/stage/Stage.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Mouse.hpp>
#include <cstdio>
#include <format>
#include <iostream>
#include <memory>
#include <vector>
#include "game/entity/enemy/Enemy.h"
#include "game/entity/player/PlayerCharacter.h"


BattleStage::BattleStage(std::vector<std::unique_ptr<Enemy>> enemies,
                         std::unique_ptr<PlayerCharacter> player)
    : m_enemies(std::move(enemies)),
      m_player(std::move(player)),
      m_deck{DeckManager::createDeck()},
      m_selectedCard{-1},
      m_hoveredEnemy{*m_enemies[0]},
      m_allEnemiesDead{false},
      m_playerDead{false},
      m_cardsPlayed{0},
      m_wasMousePressed{false},
      m_drawCounterText(WindowManager::getFont()),
      Stage()
{
    m_deck.activateCards(8);
    m_drawCounterText.setFont(WindowManager::getFont());
    m_drawCounterText.setCharacterSize(20);
    m_drawCounterText.setFillColor(sf::Color::White);
    m_drawCounterText.setPosition({10.f, 10.f});
    updateDrawCounterDisplay();

    std::cout << "BattleStage initialized\n";
}

void BattleStage::update() {
    sf::RenderWindow& window = WindowManager::getWindow();

    bool mouseCurrentlyPressed = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
    bool mouseJustPressed = mouseCurrentlyPressed && !m_wasMousePressed;
    m_wasMousePressed = mouseCurrentlyPressed;

   m_player->draw();
m_player->getHealthPool().draw({
    m_player->getSprite().getPosition().x - 30.f,
    m_player->getSprite().getPosition().y - 60.f
});

m_playerDead = m_player->getHealthPool().isDead();
m_allEnemiesDead = true;
for (const auto& enemy : m_enemies) {
    if (!enemy->getHealthPool().isDead()) m_allEnemiesDead = false;
    enemy->draw();
    enemy->getHealthPool().draw({
        enemy->getSprite().getPosition().x - 30.f,
        enemy->getSprite().getPosition().y - 60.f
    });
}
if (m_allEnemiesDead)  
    {
    m_drawCounterText.setString("You win!");
    window.draw(m_drawCounterText);
    return;
    } 
    else if (m_playerDead) 
    {
    m_drawCounterText.setString("You lose!");
    window.draw(m_drawCounterText);
    return;
    }

    std::vector<std::shared_ptr<Card>>& cards = m_deck.getCards();

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
                    card->use(*m_player, *m_player);
                else if (m_hoveredEnemy != nullptr) card->use(*m_player, *m_hoveredEnemy);

                m_selectedCard = -1;
                m_deck.deactivateCard(card);
                m_cardsPlayed += 1;


                if (m_cardsPlayed % 3 == 0) {
                    refreshHand();
                    m_selectedCard = -1;
                    for (auto& enemy : m_enemies) {
                        enemy->attack(*m_player);
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

    for (std::unique_ptr<Enemy>& enemy : m_enemies) {
        if (enemy->getSprite().getGlobalBounds().contains(mousePos)) {
            m_hoveredEnemy = enemy.get();
            m_playerHovered = false;
            return true;
        }
    }

    if (m_player->getSprite().getGlobalBounds().contains(mousePos)) {
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
    std::vector<std::shared_ptr<Card>> active = m_deck.getCards();
    for (auto& card : active) {
        m_deck.deactivateCard(card);
    }

    if (m_deck.getInactiveCount() < 8) {
        m_deck.reshuffleDiscard();
    }

    m_deck.activateCards(8);
}

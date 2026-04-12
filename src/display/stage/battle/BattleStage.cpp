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


// Main constructor: takes ownership via unique_ptr
BattleStage::BattleStage(std::vector<std::unique_ptr<Enemy>> enemies,
                         std::unique_ptr<PlayerCharacter> player)
    : m_enemies(std::move(enemies)),
      m_player(std::move(player)),
      m_deck{DeckManager::createDeck()},
      m_selectedCard{-1},
      m_hoveredEnemy{*m_enemies[0]},
      Stage()
{
    m_deck.activateCards(4);
    std::cout << "BattleStage initialized\n";
}

void BattleStage::update() {
    sf::RenderWindow& window = WindowManager::getWindow();
    m_player->draw();

    for (const auto& enemy : m_enemies) {
        enemy->draw();
    }

    std::vector<std::shared_ptr<Card>>& cards = m_deck.getCards();

    for (int i = 0; i < cards.size(); ++i) {
        std::shared_ptr<Card> card = cards.at(i);

        if (card->isHovered() && m_selectedCard == -1) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                m_selectedCard = i;
            }
        }

        if (m_selectedCard == i) {
            sf::Vector2f mousePos = WindowManager::getMousePos();
            card->drawFloating(mousePos);

            if (isCharacterHovered() && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                if (m_playerHovered)
                    card->use(*m_player, *m_player);
                else
                    card->use(m_hoveredEnemy, *m_player);
                std::cout << "hit\n";
                m_selectedCard = -1;
                m_deck.deactivateCard(card);
            }
        } else card->draw(i, cards.size());

    }
}

bool BattleStage::isCharacterHovered() {
    sf::Vector2f mousePos = WindowManager::getMousePos();

    for (std::unique_ptr<Enemy>& enemy : m_enemies) {
        if (enemy->getSprite().getGlobalBounds().contains(mousePos)) {
            m_hoveredEnemy = *enemy;
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

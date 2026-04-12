#include "Card.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "WindowManager.h"
#include "game/Constants.h"

Card::Card(std::string name, std::string description) : m_name{name}, m_description{description}, m_rect({GameConstants::CARD_WIDTH, GameConstants::CARD_HEIGHT}) {}

void Card::draw(int position, int cardCount) {
    sf::RenderWindow& window = WindowManager::getWindow();
    m_rect.setOrigin({GameConstants::CARD_WIDTH/2.f, GameConstants::CARD_HEIGHT/2.f});
    m_rect.setPosition({GameConstants::WINDOW_WIDTH / 2.f - cardCount / 2.f * GameConstants::CARD_WIDTH + GameConstants::CARD_WIDTH * position, GameConstants::CARD_Y_START});
    m_rect.setFillColor(sf::Color::Blue);
    m_rect.setOutlineColor(sf::Color::Black);
    m_rect.setOutlineThickness(2.f);
    window.draw(m_rect);
}

bool Card::isHovered() {
    sf::Vector2f mousePos = WindowManager::getMousePos();
    bool hovered = m_rect.getGlobalBounds().contains(mousePos);
    if (hovered)
        m_rect.setScale({1.5f, 1.5f});
    else m_rect.setScale({1.f, 1.f});
    return hovered;
}

void Card::drawFloating(sf::Vector2f pos) {
    sf::RenderWindow& window = WindowManager::getWindow();
    m_rect.setOrigin({GameConstants::CARD_WIDTH/2.f, GameConstants::CARD_HEIGHT/2.f});
    m_rect.setPosition(pos);
    m_rect.setFillColor(sf::Color::Blue);
    m_rect.setOutlineColor(sf::Color::Black);
    m_rect.setOutlineThickness(2.f);
    window.draw(m_rect);
}

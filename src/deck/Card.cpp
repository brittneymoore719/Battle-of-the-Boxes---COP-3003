#include "Card.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
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
    drawInternals();
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
    drawInternals();
}

void Card::drawInternals() {
    sf::RenderWindow& window = WindowManager::getWindow();
    sf::Vector2f position{m_rect.getPosition()};

    sf::Text name_text(WindowManager::getFont());
    name_text.setFillColor(sf::Color::Red);
    name_text.setString(m_name);
    name_text.setCharacterSize(14);
    name_text.setScale(m_rect.getScale());
    name_text.setStyle(sf::Text::Bold);
    sf::FloatRect name_text_bounds = name_text.getLocalBounds();
    name_text.setOrigin({name_text_bounds.size.x/2, m_rect.getSize().y/2});
    name_text.setPosition(position - sf::Vector2f{0, name_text_bounds.size.y/2 - 20});

    sf::Text description_text(WindowManager::getFont());
    description_text.setFillColor(sf::Color::Red);
    description_text.setString(m_description);
    description_text.setCharacterSize(14);
    description_text.setScale(m_rect.getScale());
    sf::FloatRect description_text_bounds = description_text.getLocalBounds();
    description_text.setOrigin({description_text_bounds.size.x/2, m_rect.getSize().y/2 - 20});
    description_text.setPosition(position + sf::Vector2f{0, m_rect.getSize().y/2});

    window.draw(name_text);
    window.draw(description_text);
}

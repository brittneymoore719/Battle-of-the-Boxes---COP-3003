
#include "UiButton.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>
#include <format>
#include <iostream>
#include "WindowManager.h"

UiButton::UiButton(std::string label, sf::Vector2f position, sf::Vector2f size) : m_clicked{false}, m_rect{size} {
    m_label = label;
    m_rect.setOrigin(size.componentWiseDiv({2.0f, 2.0f}));
    m_rect.setPosition(position);
}

void UiButton::update() {
    sf::RenderWindow& window = WindowManager::getWindow();

    if (isHovered()) {
        m_rect.setFillColor(sf::Color::Green);
        m_clicked = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
    }
    else
        m_rect.setFillColor(sf::Color::Blue);

    sf::Text label_text(WindowManager::getFont());
    label_text.setFillColor(sf::Color::Red);
    label_text.setString(m_label);
    label_text.setCharacterSize(24); // font size

    // roughly centers the text
    sf::FloatRect label_text_bounds = label_text.getLocalBounds();
    sf::FloatRect rect_bounds = m_rect.getGlobalBounds();
    label_text.setPosition(rect_bounds.position + rect_bounds.size.componentWiseDiv({2, 2}) - label_text_bounds.size.componentWiseDiv({2, 2}));

    window.draw(m_rect);
    window.draw(label_text);
}

bool UiButton::hasBeenClicked() {
    return m_clicked;
}

bool UiButton::isHovered() {
    sf::Vector2f mousePos = WindowManager::getMousePos();
    return m_rect.getGlobalBounds().contains(mousePos);
}

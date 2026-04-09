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

UiButton::UiButton(std::string label, sf::Vector2f position, sf::Vector2f size) : m_clicked{false}, m_pos{position}, m_size{size} {
    m_label = label;
}

void UiButton::update() {
    sf::RenderWindow& window = WindowManager::getWindow();

    sf::RectangleShape rect(m_size);
    rect.setPosition(m_pos);

    if (isHovered()) {
        rect.setFillColor(sf::Color::Green);
        m_clicked = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
    }
    else
        rect.setFillColor(sf::Color::Blue);

    sf::Text label_text(WindowManager::getFont());
    label_text.setFillColor(sf::Color::Red);
    label_text.setString(m_label);
    label_text.setCharacterSize(24); // font size

    // roughly centers the text
    sf::FloatRect label_text_bounds = label_text.getLocalBounds();
    label_text.setPosition({m_pos.x + m_size.x/2 - label_text_bounds.size.x/2, m_pos.y + m_size.y/2 - label_text_bounds.size.y/2});

    window.draw(rect);
    window.draw(label_text);
}

bool UiButton::hasBeenClicked() {
    return m_clicked;
}

bool UiButton::isHovered() {
    sf::Vector2i mousePos = WindowManager::getMousePos();
    return (mousePos.x > m_pos.x && mousePos.y > m_pos.y && mousePos.x < m_pos.x + m_size.x && mousePos.y < m_pos.y + m_size.y);
}

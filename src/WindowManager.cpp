#include "WindowManager.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include "game/Constants.h"


sf::RenderWindow WindowManager::m_window;
sf::Font WindowManager::m_font;

void WindowManager::createWindow() {
    m_window = sf::RenderWindow(sf::VideoMode({GameConstants::WINDOW_WIDTH, GameConstants::WINDOW_HEIGHT}), "Battle Of The Boxes");
    m_font = sf::Font("arial.ttf");
}

sf::RenderWindow& WindowManager::getWindow() {
    return m_window;
}

void WindowManager::handleEvents() {
    while (const std::optional event = m_window.pollEvent())
    {
        // "close requested" event: we close the window
        if (event->is<sf::Event::Closed>())
            m_window.close();
    }
}

sf::Vector2f WindowManager::getMousePos() {
    return m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
}

template<typename T>
sf::Vector2<T> WindowManager::getWindowSize() {
    return static_cast<sf::Vector2<T>>(m_window.getSize());
}

sf::Font& WindowManager::getFont(){
    return m_font;
}

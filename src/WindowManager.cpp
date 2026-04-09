#include "WindowManager.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

sf::RenderWindow WindowManager::m_window = sf::RenderWindow(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Battle Of The Boxes");
sf::Font WindowManager::m_font("arial.ttf");

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

sf::Vector2i WindowManager::getMousePos() {
    return sf::Mouse::getPosition(m_window);
}

sf::Font& WindowManager::getFont(){
    return m_font;
}

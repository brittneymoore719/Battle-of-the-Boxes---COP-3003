#include "WindowManager.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include<stdexcept>
#include "game/Constants.h"


sf::RenderWindow WindowManager::m_window;
sf::Font WindowManager::m_font;
sf::String WindowManager::m_typedInput;


void WindowManager::createWindow() {
    m_window = sf::RenderWindow(sf::VideoMode({GameConstants::WINDOW_WIDTH, GameConstants::WINDOW_HEIGHT}), "Battle Of The Boxes");

    try {
        if (!m_font.openFromFile("arial.ttf")) {
            throw std::runtime_error("arial.ttf could not be loaded");
        }
    } catch (const std::runtime_error& e) {
        std::cerr << "Font error: " << e.what() << "\n";
    }
}

sf::RenderWindow& WindowManager::getWindow() {
    return m_window;
}

void WindowManager::handleEvents() 
{
    while (const std::optional event = m_window.pollEvent())
    {
        // "close requested" event: we close the window
        if (event->is<sf::Event::Closed>())
            m_window.close();
        if (const auto* textEvent = event->getIf<sf::Event::TextEntered>()) 
        {
            if (textEvent->unicode == 8 && !m_typedInput.isEmpty()) 
            {
                m_typedInput = m_typedInput.substring(0, m_typedInput.getSize() - 1);
            } 
            else if (textEvent->unicode >= 32 && textEvent->unicode < 128) 
            {
                m_typedInput += textEvent->unicode;
            }
        }
    }
}


sf::Vector2f WindowManager::getMousePos() {
    return m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
}

sf::Font& WindowManager::getFont(){
    return m_font;
}

sf::String WindowManager::getTypedInput() 
{
    return m_typedInput;
}

void WindowManager::clearTypedInput() 
{
    m_typedInput.clear();

}
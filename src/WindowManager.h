#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H


#include <SFML/Graphics.hpp>

class WindowManager {
public:
    static sf::RenderWindow& getWindow();
    static void handleEvents();
    static sf::Vector2f getMousePos();
    static sf::Font& getFont();
private:
    static sf::RenderWindow m_window;
    static sf::Font m_font;
};

#endif

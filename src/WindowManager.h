#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H


#include <SFML/Graphics.hpp>

class WindowManager {
public:
    static void createWindow();
    static sf::RenderWindow& getWindow();
    static void handleEvents();
    static sf::Vector2f getMousePos();
    static sf::Font& getFont();

    template<typename T>
    static sf::Vector2<T> getWindowSize() {
        return static_cast<sf::Vector2<T>>(m_window.getSize());
    }

private:
    static sf::RenderWindow m_window;
    static sf::Font m_font;
};

#endif

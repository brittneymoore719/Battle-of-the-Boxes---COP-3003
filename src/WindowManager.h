#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H


#include <SFML/Graphics.hpp>

class WindowManager {
public:
    static void createWindow();
    static sf::RenderWindow& getWindow();
    static void handleEvents();
    static sf::Vector2f getMousePos();
    template<typename T>
    static sf::Vector2<T> getWindowSize();
    static sf::Font& getFont();
private:
    static sf::RenderWindow m_window;
    static sf::Font m_font;
};

#endif

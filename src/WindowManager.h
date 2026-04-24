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
    static sf::String getTypedInput();
    static void clearTypedInput();
   private:
    static sf::RenderWindow m_window;
    static sf::Font m_font;
    static sf::String m_typedInput;
};

#endif

#ifndef CARD_H
#define CARD_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <string>

class Character;

class Card {
    public:
    Card(std::string name, std::string description);
    void draw(int position, int cardCount);
    bool isHovered();
    void drawFloating(sf::Vector2f newPos);
    void drawInternals();

    virtual bool use(Character& user, Character& target) = 0;

    private:
    sf::RectangleShape m_rect;

    std::string m_name;
    std::string m_description;
};

#endif

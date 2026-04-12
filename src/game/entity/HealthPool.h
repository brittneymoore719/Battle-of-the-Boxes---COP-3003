#ifndef HEALTHPOOL_H
#define HEALTHPOOL_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
class HealthPool {
    public:
    explicit HealthPool(int max_hp);

    void draw(sf::Vector2f display_position);

    private:
    sf::RectangleShape m_rect;
    int m_max_health;
    int m_current_health;
    int m_block;
};

#endif

#ifndef HEALTHPOOL_H
#define HEALTHPOOL_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
class HealthPool {
    public:
    explicit HealthPool(double max_hp);
    void takeDamage(double damageAmount);
    bool isDead();

    void draw(sf::Vector2f display_position);

    private:
    sf::RectangleShape m_rect;
    double m_max_health;
    double m_current_health;
    double m_block;
};

#endif

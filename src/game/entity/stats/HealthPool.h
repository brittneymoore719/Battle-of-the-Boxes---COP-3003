#ifndef HEALTHPOOL_H
#define HEALTHPOOL_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

template <typename T>
T clamp(T value, T low, T high) {
    if (value < low) return low;
    if (value > high) return high;
    return value;
}

class HealthPool {
    public:
    explicit HealthPool(double max_hp);
    void takeDamage(double damageAmount);
    bool isDead();
    void resetBlock();
    void addBlock(double blockAmount);

    void draw(sf::Vector2f display_position);
    double getCurrentHealth() const;
    double getBlock() const;

    private:
    sf::RectangleShape m_rect;
    double m_max_health;
    double m_current_health;
    double m_block;
};

#endif

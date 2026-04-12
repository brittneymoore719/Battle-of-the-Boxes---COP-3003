#include "HealthPool.h"
#include <SFML/System/Vector2.hpp>
#include <iostream>

HealthPool::HealthPool(double max_hp) : m_max_health{max_hp}, m_current_health{max_hp}, m_block{0} {}

void HealthPool::draw(sf::Vector2f display_position) {

}

void HealthPool::takeDamage(double damageAmount) {
    m_current_health -= damageAmount;
    std::cout << "hp: " << m_current_health << "\n";
}

bool HealthPool::isDead() {
    if (m_current_health < 0) {
        m_current_health = 0;
    };
    return m_current_health == 0;
}

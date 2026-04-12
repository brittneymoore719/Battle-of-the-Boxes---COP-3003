#include "HealthPool.h"
#include <SFML/System/Vector2.hpp>

HealthPool::HealthPool(int max_hp) : m_max_health{max_hp}, m_current_health{max_hp}, m_block{0} {}

void HealthPool::draw(sf::Vector2f display_position) {

}

void HealthPool::takeDamage(int damageAmount) {
    m_current_health -= damageAmount;
}

bool HealthPool::isDead() {
    if (m_current_health < 0) {
        m_current_health = 0;
    };
    return m_current_health == 0;
}

#include "HealthPool.h"
#include <SFML/System/Vector2.hpp>
#include <iostream>

HealthPool::HealthPool(double max_hp) : m_max_health{max_hp}, m_current_health{max_hp}, m_block{0} {}

void HealthPool::draw(sf::Vector2f display_position) {

}

void HealthPool::takeDamage(double damageAmount) {
    double initialDamageAmount{damageAmount};
    damageAmount -= m_block;
    m_block -= initialDamageAmount;
    if (damageAmount < 0) damageAmount = 0;
    if (m_block < 0) m_block = 0;

    m_current_health -= damageAmount;
    std::cout << "hp: " << m_current_health << "\n";
}

void HealthPool::addBlock(double blockAmount) {
    m_block += blockAmount;
}

void HealthPool::resetBlock() {
    m_block = 0;
}

bool HealthPool::isDead() {
    if (m_current_health < 0) {
        m_current_health = 0;
    };
    return m_current_health == 0;
}

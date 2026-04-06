#include <iostream>
#include "Player.h"

void Player::takeDamage(int damage) {
    if (damage < 0) {
        throw GameException("Damage cannot be negative.");
    }

    m_health -= damage;
    if (m_health < 0) {
        m_health = 0;
        std::cout << m_name << " has been defeated!" << std::endl;
    }
}

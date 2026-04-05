#include <iostream>
#include "Player.h"

void Player::takeDamage(int damage) {
    m_health -= damage;
    if (m_health < 0) {
        m_health = 0;
        std::cout << "Player has been defeated!" << std::endl;
    }
}

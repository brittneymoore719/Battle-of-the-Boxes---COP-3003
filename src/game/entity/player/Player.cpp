#include <iostream>
#include "Player.h"
#include "game/Constants.h"

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

void Player::heal(int amount) {
    if (amount < 0) {
        throw GameException("Heal amount cannot be negative! ");
    }

    m_health += amount;
    if (m_health > GameConstants::MAX_PLAYER_HEALTH) {
        m_health = GameConstants::MAX_PLAYER_HEALTH;
    }
    std::cout << m_name << "healed " << amount << "HP!! " << std::endl;
}

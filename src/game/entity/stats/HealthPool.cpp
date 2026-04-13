#include "HealthPool.h"
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include "WindowManager.h"

HealthPool::HealthPool(double max_hp) : m_max_health{max_hp}, m_current_health{max_hp}, m_block{0} {}

void HealthPool::draw(sf::Vector2f display_position) {
    sf::RenderWindow& window = WindowManager::getWindow();

    sf::RectangleShape background({120.f, 16.f});
    background.setPosition(display_position);
    background.setFillColor(sf::Color(80, 80, 80));

    sf::RectangleShape healthBar({120.f * static_cast<float>(m_current_health / m_max_health), 16.f});
    healthBar.setPosition(display_position);
    healthBar.setFillColor(sf::Color::Red);

    sf::RectangleShape blockBar({120.f * static_cast<float>(m_block / m_max_health), 6.f});
    blockBar.setPosition({display_position.x, display_position.y + 18.f});
    blockBar.setFillColor(sf::Color::Blue);

    window.draw(background);
    window.draw(healthBar);
    window.draw(blockBar);
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

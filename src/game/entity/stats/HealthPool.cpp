#include "HealthPool.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include "WindowManager.h"

HealthPool::HealthPool(double max_hp) : m_max_health{max_hp}, m_current_health{max_hp}, m_block{0} {}

void HealthPool::draw(sf::Vector2f display_position) {
    sf::RenderWindow& window = WindowManager::getWindow();

    if (m_max_health <= 0.0) return;

    const float bar_width = 100.0f;
    const float bar_height = 12.0f;
    const float spacing = 4.0f;
    const float total_height = 2.0f * bar_height + spacing;

    sf::Vector2f top_left(display_position.x - bar_width / 2.0f,
                          display_position.y - total_height / 2.0f);

    if (m_block > 0.0) {
        float block_ratio = std::min(1.0, m_block / m_max_health);
        float block_width = bar_width * block_ratio;

        sf::RectangleShape block_bar(sf::Vector2f(block_width, bar_height));
        block_bar.setFillColor(sf::Color(100, 150, 255));  // light blue
        block_bar.setPosition({top_left.x, top_left.y});
        window.draw(block_bar);

        sf::RectangleShape block_bg(sf::Vector2f(bar_width, bar_height));
        block_bg.setFillColor(sf::Color::Transparent);
        block_bg.setOutlineThickness(1.0f);
        block_bg.setOutlineColor(sf::Color::White);
        block_bg.setPosition({top_left.x, top_left.y});
        window.draw(block_bg);
    }
    sf::RectangleShape health_bg(sf::Vector2f(bar_width, bar_height));
    health_bg.setFillColor(sf::Color(60, 0, 0));
    health_bg.setPosition({top_left.x, top_left.y + bar_height + spacing});
    window.draw(health_bg);

    float health_ratio = std::min(1.0, m_current_health / m_max_health);
    float health_width = bar_width * health_ratio;

    sf::RectangleShape health_fill(sf::Vector2f(health_width, bar_height));
    health_fill.setFillColor(sf::Color::Red);
    health_fill.setPosition({top_left.x, top_left.y + bar_height + spacing});
    window.draw(health_fill);
}

void HealthPool::takeDamage(double damageAmount) {
    double initialDamageAmount{damageAmount};
    damageAmount -= m_block;
    m_block -= initialDamageAmount;
    if (damageAmount < 0) damageAmount = 0;
    if (m_block < 0) m_block = 0;

    m_current_health -= damageAmount;
    m_current_health = clamp(m_current_health, 0.0, m_max_health);
}

void HealthPool::addBlock(double blockAmount) {
    m_block += blockAmount;
    m_block = clamp(m_block, 0.0, m_max_health);
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

double HealthPool::getCurrentHealth() const {
    return m_current_health;
}

double HealthPool::getBlock() const {
    return m_block;
}

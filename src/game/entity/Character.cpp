#include "Character.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include "WindowManager.h"
#include "stats/HealthPool.h"

//basic constructor for the Box, this is subject to change
Character::Character(const std::filesystem::path texturePath, int max_hp) 
: m_texture(sf::Texture(texturePath)), m_healthPool(max_hp),  m_sprite(m_texture), m_name("Unknown") 
{
    m_sprite.setOrigin(m_sprite.getGlobalBounds().size.componentWiseDiv({2, 2}));
}

sf::Texture& Character::getTexture() {
    return m_texture;
}

sf::Sprite& Character::getSprite() {
    return m_sprite;
}

HealthPool& Character::getHealthPool() {
    return m_healthPool;
}

std::string Character::getName() const 
{
    return m_name;
}

void Character::setName(const std::string& name) 
{
    m_name = name;
}


void Character::draw() {
    sf::RenderWindow& window{WindowManager::getWindow()};
    window.draw(m_sprite);
    m_healthPool.draw(m_sprite.getPosition() + sf::Vector2f{m_sprite.getLocalBounds().size.x/2, -100.0f});
}

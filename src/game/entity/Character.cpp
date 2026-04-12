#include "Character.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "../Constants.h"
#include "WindowManager.h"
#include "game/entity/HealthPool.h"

//basic constructor for the Box, this is subject to change
Character::Character(const std::filesystem::path texturePath, int max_hp) : m_texture(sf::Texture(texturePath)), m_healthPool(max_hp),  m_sprite(m_texture) {
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


void Character::draw() {
    sf::RenderWindow& window{WindowManager::getWindow()};
    window.draw(m_sprite);
}

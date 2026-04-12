#ifndef BATTLE_OF_THE_BOXES___COP_3003_CHARACTER_H
#define BATTLE_OF_THE_BOXES___COP_3003_CHARACTER_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <array>
#include <memory>
#include <vector>
#include "game/entity/HealthPool.h"


class Character {
    public:

    Character(const std::filesystem::path texturePath, int max_hp);

    sf::Texture& getTexture();
    sf::Sprite& getSprite();
    HealthPool& getHealthPool();


    void draw();

private:
    HealthPool m_healthPool;
    sf::Texture m_texture;
    sf::Sprite m_sprite;

};

#endif //BATTLE_OF_THE_BOXES___COP_3003_CHARACTER_H

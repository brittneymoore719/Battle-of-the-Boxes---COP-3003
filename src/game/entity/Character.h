#ifndef BATTLE_OF_THE_BOXES___COP_3003_CHARACTER_H
#define BATTLE_OF_THE_BOXES___COP_3003_CHARACTER_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <array>
#include <memory>
#include <vector>


class Character {
    public:

    Character(const std::filesystem::path texturePath);

    sf::Texture& getTexture();
    sf::Sprite& getSprite();



    void draw();

private:

    sf::Texture m_texture;
    sf::Sprite m_sprite;

};

#endif //BATTLE_OF_THE_BOXES___COP_3003_CHARACTER_H

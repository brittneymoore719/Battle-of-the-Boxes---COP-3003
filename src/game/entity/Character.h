#ifndef BATTLE_OF_THE_BOXES___COP_3003_CHARACTER_H
#define BATTLE_OF_THE_BOXES___COP_3003_CHARACTER_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <array>
#include <memory>
#include <vector>

#include "game/combat/deck/Deck.h"
#include "stats/HealthPool.h"
#include <string>


class Character {
    public:
    virtual ~Character() = default;

    Character(const std::filesystem::path texturePath, int max_hp);

    sf::Texture& getTexture();
    sf::Sprite& getSprite();
    HealthPool& getHealthPool();
    Deck& getDeck();

    std::string getName() const;
    void setName(const std::string& name);

    void draw();

private:

    HealthPool m_healthPool;
    Deck m_deck;
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    std::string m_name;

};

#endif //BATTLE_OF_THE_BOXES___COP_3003_CHARACTER_H

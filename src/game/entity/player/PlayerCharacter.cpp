//
// Created by Ethan Pedrick on 4/1/26.
// Updated by Brittney Moore on 4/7/2026

#include "PlayerCharacter.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include "WindowManager.h"
#include "game/entity/Character.h"
#include "game/Constants.h"

PlayerCharacter::PlayerCharacter()
    : Character(
        "sprites/box.png") {
            sf::Sprite& sprite = getSprite();
            sprite.setPosition({GameConstants::PLAYER_POS_X, GameConstants::PLAYER_POS_Y});
            sprite.setScale({GameConstants::PLAYER_SCALE, GameConstants::PLAYER_SCALE});
        }

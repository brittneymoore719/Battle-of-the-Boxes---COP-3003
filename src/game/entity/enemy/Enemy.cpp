//edited by Brittney Moore 4/6/2026
#include "../Character.h"
#include "game/Constants.h"
#include "Enemy.h"

Enemy::Enemy(int position, int max_health, const std::filesystem::path texturePath)
    : Character(texturePath, max_health) {
          setPosition(position);
      }

void Enemy::setPosition(int position) {
    sf::Sprite& sprite = getSprite();
    sprite.setPosition({GameConstants::ENEMY_POS_X + GameConstants::ENEMY_GAP * position, GameConstants::ENEMY_POS_Y});
    sprite.setScale({GameConstants::ENEMY_SCALE, GameConstants::ENEMY_SCALE});
}

//Enemy-specific logic will be held here
//enemies will inherit health and movement from the character

#include "Zombie.h"
#include "game/Constants.h"

Zombie::Zombie(int position) : Enemy(position, GameConstants::MAX_ENEMY_HEALTH, "sprites/zombie_worker.png") {}

void Zombie::attack(Character& target) {
    target.getHealthPool().takeDamage(GameConstants::ENEMY_ATTACK_DAMAGE);
}

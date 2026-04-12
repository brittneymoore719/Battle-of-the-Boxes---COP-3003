//edited by Brittney Moore 4/6/2026
#include "../Character.h"
#include "Enemy.h"

Enemy::Enemy(std::string name, EnemyType type, double maxHp, double baseDmg, double defense, double accuracy, const std::filesystem::path texturePath)
    : Character(texturePath, maxHp, maxHp, baseDmg, 0.0, defense, 0.0, accuracy),
      m_name(name),
      m_type(type){}


std::string Enemy::getName() const { return m_name; }

bool Enemy::isAlive() const { return getStatistic(CURRENT_HP) > 0; }

EnemyType Enemy::getType() const { return m_type; }

//Enemy-specific logic will be held here
//enemies will inherit health and movement from the character

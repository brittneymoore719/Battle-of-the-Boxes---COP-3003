//edited by Brittney Moore 4/6/2026

#ifndef BATTLE_OF_THE_BOXES___COP_3003_ENEMY_H
#define BATTLE_OF_THE_BOXES___COP_3003_ENEMY_H
#include "../Character.h"
#include "../../Enums.h"
#include <string>

class Enemy : public Character {
public:
    Enemy(std::string name,
        EnemyType type,
        double maxHp = 30,
        double baseDmg = 8.0,
        double defense = 0.5,
        double accuracy = 0.7,
        const std::filesystem::path texturePath = "sprites/box.png"
    );

    std::string getName() const;
    bool isAlive() const;
    EnemyType getType() const;

    private:
    std::string m_name;
     EnemyType m_type;
};

#endif //BATTLE_OF_THE_BOXES___COP_3003_ENEMY_H

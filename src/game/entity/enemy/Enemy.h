//edited by Brittney Moore 4/6/2026

#ifndef BATTLE_OF_THE_BOXES___COP_3003_ENEMY_H
#define BATTLE_OF_THE_BOXES___COP_3003_ENEMY_H
#include "../Character.h"
#include <string>

class Enemy : public Character {
public:
    Enemy(int position,
        const std::filesystem::path texturePath = "sprites/zombie_worker.png"
    );

    void setPosition(int position);

    private:
    std::string m_name;
};

#endif //BATTLE_OF_THE_BOXES___COP_3003_ENEMY_H

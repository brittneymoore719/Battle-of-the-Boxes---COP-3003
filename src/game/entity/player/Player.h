//
// Created by Ethan Pedrick on 4/1/26.
//

#ifndef BATTLE_OF_THE_BOXES___COP_3003_PLAYER_H
#define BATTLE_OF_THE_BOXES___COP_3003_PLAYER_H

#include <string>
#include "game/GameException.h"

class Player {
public:
    Player(const std::string& name = "Player", int health = 100)
        : m_name(name), m_health(health) {
        if (health <= 0) {
            throw GameException("Player health must be greater than 0.");
        }
    }

    const std::string& getName() const {
        return m_name;
    }

    int getHealth() const {
        return m_health;
    }

    bool isAlive() const {
        return m_health > 0;
    }

    void heal(int amount);
    void takeDamage(int damage);

private:
    std::string m_name;
    int m_health;
};

#endif

//Edited by Woodolph sylvain 4/5/26
//edited by Brittney Moore 4/7/2026

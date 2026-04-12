//
// Created by Ethan Pedrick on 4/1/26.
// updated by Brittney Moore on 4/7/2026

#ifndef BATTLE_OF_THE_BOXES___COP_3003_PLAYERCHARACTER_H
#define BATTLE_OF_THE_BOXES___COP_3003_PLAYERCHARACTER_H
#include "game/entity/GameCharacter.h"


class PlayerCharacter : public GameCharacter {
    public:
    double getHealth();
    void handleUserInput();
    int getUserAction();
    PlayerCharacter();

    private:
    int m_selectedAction{0};
};

#endif //BATTLE_OF_THE_BOXES___COP_3003_PLAYERCHARACTER_H

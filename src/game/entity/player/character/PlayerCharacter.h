//
// Created by Ethan Pedrick on 4/1/26.
//

#ifndef BATTLE_OF_THE_BOXES___COP_3003_PLAYERCHARACTER_H
#define BATTLE_OF_THE_BOXES___COP_3003_PLAYERCHARACTER_H
#include "../../Character.h"
#include "game/entity/Character.h"
class PlayerCharacter : public Character {
    public:
    double getHealth();
    void handleUserInput();
    int getUserAction();
    bool dodged();
    private:
    int m_selectedAction{0};
    bool m_dodged;
};

#endif //BATTLE_OF_THE_BOXES___COP_3003_PLAYERCHARACTER_H

//
// Created by Ethan Pedrick on 4/5/2026.
//

#ifndef BATTLE_OF_THE_BOXES_COMBATANT_H
#define BATTLE_OF_THE_BOXES_COMBATANT_H
#include "game/entity/Character.h"

class Combatant {

public:

    Combatant(Character& character);

    virtual void act();

private:

    const Character& m_character; // The character the combatant is related to

};

#endif //BATTLE_OF_THE_BOXES_COMBATANT_H
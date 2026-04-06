//
// Created by Ethan Pedrick on 4/5/2026.
//
//
//Edited by Woodolph Sylvain 4/5/26
//

#ifndef BATTLE_OF_THE_BOXES_COMBATANT_H
#define BATTLE_OF_THE_BOXES_COMBATANT_H

#include "game/entity/Character.h"

class Combatant {
public:
    explicit Combatant(Character& character);
    virtual ~Combatant() = default;

    virtual void act(Character& target);

    Character& getCharacter();

protected:
    Character& m_character;
};

#endif

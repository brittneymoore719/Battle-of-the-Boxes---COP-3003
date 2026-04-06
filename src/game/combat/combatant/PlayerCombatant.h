//
// Created by Ethan Pedrick on 4/5/2026.
//
//Edited by Woodolph Sylvain 4/5/06
#ifndef BATTLE_OF_THE_BOXES_PLAYERCOMBATANT_H
#define BATTLE_OF_THE_BOXES_PLAYERCOMBATANT_H
#include "Combatant.h"

class PlayerCombatant : public Combatant 
{
public:
    explicit PlayerCombatant(Character& character);

    void act(Character& target) override;

};

#endif //BATTLE_OF_THE_BOXES_PLAYERCOMBATANT_H

//
// Created by Ethan Pedrick on 4/5/2026.
//
//edited by Woodolph Sylvain 4/5/06

#include "PlayerCombatant.h"

PlayerCombatant::PlayerCombatant(Character& character)
    : Combatant(character) {}

void PlayerCombatant::act(Character& target) 
{
    double damage = m_character.getStatistic(BASE_DMG);
    target.takeDamage(damage);
}

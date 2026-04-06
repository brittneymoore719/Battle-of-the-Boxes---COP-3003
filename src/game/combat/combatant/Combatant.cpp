//
// Created by Ethan Pedrick on 4/5/2026.
//
//Edited by Woodolph Sylvain 4/5/06
#include "Combatant.h"

Combatant::Combatant(Character& character)
    : m_character(character) {}

Character& Combatant::getCharacter() {
    return m_character;
}

void Combatant::act(Character& target) {}

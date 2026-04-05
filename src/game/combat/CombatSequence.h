//
// Created by Ethan Pedrick on 4/2/26.
//

#ifndef BATTLE_OF_THE_BOXES_COMBATSEQUENCE_H
#define BATTLE_OF_THE_BOXES_COMBATSEQUENCE_H
#include <array>
#include <cstdint>

#include "game/entity/Character.h"


enum Action {ATTACK, BLOCK, FEINT};

class CombatSequence {

public:

    CombatSequence(const std::array<Character, 2>& combatants);

    std::array<Character, 2> getCombatants();


private:

    std::array<Character, 2> m_combatants;

};


#endif //BATTLE_OF_THE_BOXES_COMBATSEQUENCE_H

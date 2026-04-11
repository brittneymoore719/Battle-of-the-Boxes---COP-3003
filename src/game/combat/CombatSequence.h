//
// Created by Ethan Pedrick on 4/2/26.
//

#ifndef BATTLE_OF_THE_BOXES_COMBATSEQUENCE_H
#define BATTLE_OF_THE_BOXES_COMBATSEQUENCE_H
#include <array>
#include <cstdint>

#include "combatant/Combatant.h"
#include "game/entity/Character.h"
#include "game/entity/player/character/PlayerCharacter.h"


enum Action {ATTACK, DEFEND, FEINT, PASS};

class CombatSequence {

public:

    CombatSequence(PlayerCharacter& player, Character& character);

    void playRound();

    std::array<Combatant, 2>& getCombatants() const;

    bool getTurn() const;

    int getRound() const;


private:

    std::array<Combatant, 2>& m_combatants;

    bool m_turn;

    int m_round;

};


#endif //BATTLE_OF_THE_BOXES_COMBATSEQUENCE_H
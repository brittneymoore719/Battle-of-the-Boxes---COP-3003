//
// Created by Ethan Pedrick on 4/2/26.
//

#include "CombatSequence.h"

#include "combatant/PlayerCombatant.h"

CombatSequence::CombatSequence(PlayerCharacter& player, Character& character) {

    PlayerCombatant playerCombatant(player);
    Combatant defender(character);

    m_combatants({player, character}),
    m_round(0),
    m_turn(0)


}

void CombatSequence::playRound() {
    //get attacker and defender absed on whose turn it is
    Combatant& attacker = m_combatants[m_turn];
    Combatant& defender = m_combatants[!m_turn];

    //attacker atacks defender
    attacker.act(defender.getCharacter());

    //switch
    m_turn = !m_turn;

    //add count to round counter
    m_round++;


}

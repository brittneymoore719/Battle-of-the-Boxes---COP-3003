//
// Created by Ethan Pedrick on 4/2/26.
//

#include "CombatSequence.h"
#include "game/entity/GameCharacter.h"
#include "game/entity/player/character/PlayerCharacter.h"

CombatSequence::CombatSequence(PlayerCharacter& player, GameCharacter& character) :

    m_player(player),
    m_character(character),
    m_combatants{&m_player, &m_character},
    m_round(0),
    m_turn(0)

{}

GameCharacter& CombatSequence::getOpponent() const {
    return m_character;
}

PlayerCharacter& CombatSequence::getPlayer() const {
    return m_player;
}

void CombatSequence::playRound() {
    //get attacker and defender absed on whose turn it is
    GameCharacter& attacker = *m_combatants[m_turn];
    GameCharacter& defender = *m_combatants[!m_turn];

    //attacker atacks defender
    attacker.act(defender);

    //switch
    m_turn = !m_turn;

    //add count to round counter
    m_round++;

}

//
// Created by Ethan Pedrick on 4/2/26.
//

#ifndef BATTLE_OF_THE_BOXES_COMBATSEQUENCE_H
#define BATTLE_OF_THE_BOXES_COMBATSEQUENCE_H
#include <array>
#include <cstdint>

#include "game/GameObject.h"

class GameCharacter;
class PlayerCharacter;

class CombatSequence {

public:

    CombatSequence(PlayerCharacter& player, GameCharacter& character);

    void playRound();

    PlayerCharacter& getPlayer() const;

    GameCharacter& getOpponent() const;

    bool getTurn() const;

    int getRound() const;


private:

    PlayerCharacter& m_player;

    GameCharacter& m_character;

    const std::array<GameCharacter*, 2> m_combatants;

    bool m_turn;

    int m_round;

};


#endif //BATTLE_OF_THE_BOXES_COMBATSEQUENCE_H
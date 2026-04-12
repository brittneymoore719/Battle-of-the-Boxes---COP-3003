//
// Created by Ethan Pedrick on 4/12/2026.
//

#ifndef BATTLE_OF_THE_BOXES_GAME_H
#define BATTLE_OF_THE_BOXES_GAME_H
#include "game/entity/player/character/PlayerCharacter.h"

class PlayerCharacter;

class Game{
public:

    static Game& getInstance() {
        return instance;
    }

    void start();

    PlayerCharacter& getPlayer();

private:

    Game();

    static Game instance;

    PlayerCharacter m_player;

};

#endif //BATTLE_OF_THE_BOXES_GAME_H
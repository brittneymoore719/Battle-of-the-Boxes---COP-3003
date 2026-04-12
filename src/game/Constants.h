//Edited by Brittney Moore 4/6/2026
#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace GameConstants {
    //window
    const int WINDOW_WIDTH = 1280;
    const int WINDOW_HEIGHT = 720;

    // player positioning
    const float PLAYER_POS_X = WINDOW_WIDTH / 12.f * 2;
    const float PLAYER_POS_Y = WINDOW_HEIGHT / 2.f;
    const float PLAYER_SCALE = 5.0f;

    // enemy positioning
    const float ENEMY_POS_X = WINDOW_WIDTH / 14.f * 8;
    const float ENEMY_POS_Y = WINDOW_HEIGHT / 2.f;
    const float ENEMY_SCALE = 5.0f;
    const float ENEMY_GAP = WINDOW_WIDTH / 6.f;

    // card positioning
    const float CARD_WIDTH = 100.f;
    const float CARD_HEIGHT = 150.f;
    const float CARD_Y_START = WINDOW_HEIGHT - 125.f;
    const float CARD_Y_END = WINDOW_HEIGHT - 175.f;

    //player
    const int MAX_PLAYER_HEALTH = 150;
    const int PLAYER_SPEED = 5;
    const int PLAYER_ATTACK_DAMAGE = 15;

    //enemy
    const int MAX_ENEMY_HEALTH = 100;
    const int ENEMY_SPEED = 5;
    const int ENEMY_ATTACK_DAMAGE = 10;

    //combat - levels for the player to complete
    const int MAX_FLOORS = 5;
    }

#endif

#ifndef ENUMS_H
#define ENUMS_H

enum class GameState {
    MAIN_MENU,
    PLAYING,
    GAME_OVER
};


// These should really just be turned into classes rather than being an enum; enums are mostly for states
enum class EnemyType {
    ZOMBIE_WORKER,
    MANAGER,
    BEZOS_BOSS
};

#endif

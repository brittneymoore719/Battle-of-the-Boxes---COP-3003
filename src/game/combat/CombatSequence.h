//
// Created by Ethan Pedrick on 4/13/26.
//

#ifndef BATTLE_OF_THE_BOXES_COMBATSEQUENCE_H
#define BATTLE_OF_THE_BOXES_COMBATSEQUENCE_H
#include <memory>
#include <vector>

#include "display/Updatable.h"

class Enemy;
class PlayerCharacter;

enum CombatState {ONGOING, PLAYER_LOST, PLAYER_WON};

class CombatSequence : public Updatable {

public:

    CombatSequence(std::vector<std::unique_ptr<Enemy>> enemies,
                std::unique_ptr<PlayerCharacter> player);

    CombatState getState() const;

    void update() override;

    std::unique_ptr<PlayerCharacter>& getPlayer();

    std::vector<std::unique_ptr<Enemy>>& getEnemies();

    CombatState updateState();



private:

    CombatState m_state;

    std::unique_ptr<PlayerCharacter> m_player;
    std::vector<std::unique_ptr<Enemy>> m_enemies;



};

#endif //BATTLE_OF_THE_BOXES_COMBATSEQUENCE_H
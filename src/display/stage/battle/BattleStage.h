//
// Created by worm on 4/5/2026.
//

#ifndef BATTLE_OF_THE_BOXES_BATTLESTAGE_H
#define BATTLE_OF_THE_BOXES_BATTLESTAGE_H

#include "display/stage/Stage.h"
#include "game/entity/player/character/PlayerCharacter.h"
#include "game/entity/enemy/Enemy.h"
#include "game/Enums.h"
#include "game/combat/CombatSequence.h"

class BattleStage : public Stage {
public:
    BattleStage(CombatSequence& sequence);
    ~BattleStage() override = default;
    void update() override;
private:

    CombatSequence& m_combatSequence;

    PlayerCharacter m_player{};
    Enemy m_enemy{"Zombie Worker", EnemyType::ZOMBIE_WORKER};

};

#endif //BATTLE_OF_THE_BOXES_BATTLESTAGE_H

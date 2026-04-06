//
// Created by worm on 4/5/2026.
//

#ifndef BATTLE_OF_THE_BOXES_BATTLESTAGE_H
#define BATTLE_OF_THE_BOXES_BATTLESTAGE_H

#include "display/stage/Stage.h"
#include "game/entity/player/character/PlayerCharacter.h"
#include "game/entity/enemy/Enemy.h"

class BattleStage : public Stage {
public:
    BattleStage();
    virtual ~BattleStage() = default;
    virtual void update() override;
private:
    PlayerCharacter m_player{};
    Enemy m_enemy{};
};

#endif //BATTLE_OF_THE_BOXES_BATTLESTAGE_H

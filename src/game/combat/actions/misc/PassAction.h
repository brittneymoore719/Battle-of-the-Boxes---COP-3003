//
// Created by Ethan Pedrick on 4/12/2026.
//

#ifndef BATTLE_OF_THE_BOXES_PASSACTION_H
#define BATTLE_OF_THE_BOXES_PASSACTION_H
#include "game/combat/actions/GameAction.h"

class PassAction : public GameAction {

    public:

    PassAction(GameCharacter& user, GameCharacter& target);

    bool apply() override;

};

#endif //BATTLE_OF_THE_BOXES_PASSACTION_H
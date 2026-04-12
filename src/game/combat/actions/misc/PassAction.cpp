//
// Created by Ethan Pedrick on 4/12/2026.
//

#include "PassAction.h"

#include "game/entity/GameCharacter.h"

PassAction::PassAction(GameCharacter& user, GameCharacter& target) : GameAction(user, target) {

    setName("Pass");

}

bool PassAction::apply() {

    // basically do nothing
    return false;

}

#include "BasicAttack.h"
#include <string>

#include "game/entity/GameCharacter.h"

BasicAttack::BasicAttack(GameCharacter& user, GameCharacter& target):
    GameAction(user, target){

    setName("Basic Attack");

}

void BasicAttack::apply() {
    getTarget().takeDamage(getUser().getStatistic(BASE_DMG));
}

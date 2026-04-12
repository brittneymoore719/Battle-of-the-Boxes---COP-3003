#include "BasicAttack.h"
#include <string>

#include "game/entity/GameCharacter.h"

BasicAttack::BasicAttack(GameCharacter& user, GameCharacter& target):
    GameAction(user, target){

    setName("Basic Attack");

}

bool BasicAttack::apply() {

    double damage = getUser().getStatistic(BASE_DMG);

    double reduction = 0.0;

    if (getTarget().isBlocking()) {

        reduction = getTarget().getStatistic(DEFENSE);

    }

    damage -= reduction * 0.5;

    return getTarget().takeDamage(damage);
}

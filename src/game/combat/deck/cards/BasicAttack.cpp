#include "BasicAttack.h"
#include <iostream>
#include <string>

#include "game/entity/Character.h"

BasicAttack::BasicAttack(): Card("Basic Attack", "do 5 damage") {

}

bool BasicAttack::use(Character& user, Character& target) {

    if (&user == &target) {
        return false;
    }

    target.getHealthPool().takeDamage(5);
    return true;

}

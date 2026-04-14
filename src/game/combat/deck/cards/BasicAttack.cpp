#include "BasicAttack.h"
#include <iostream>
#include <string>

#include "game/entity/Character.h"

BasicAttack::BasicAttack(): Card("Basic Attack", "do 5 damage") {

}

void BasicAttack::use(Character& user, Character& target) {
    target.getHealthPool().takeDamage(5);
}

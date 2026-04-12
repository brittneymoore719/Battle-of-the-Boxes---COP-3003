#include "BasicAttack.h"
#include <string>

BasicAttack::BasicAttack(std::string name): Action(name) {

}

void BasicAttack::onUse(Character& user, Character& target) {
    target.takeDamage(user.getStatistic(Statistic::BASE_DMG));
}

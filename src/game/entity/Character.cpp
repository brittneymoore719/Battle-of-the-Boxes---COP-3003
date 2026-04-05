#include "Character.h"

//basic constructor for the Box, this is subject to change
Character::Character(
        double maxHp,
        double currentHp,
        double baseDmg,
        double pierce,
        double defense,
        double dodge,
        double accuracy,
        double critChance,
        double critMultiplier
    ) : m_statistics({maxHp, currentHp, baseDmg, pierce, defense, dodge, accuracy, critChance, critMultiplier}) {}


double Character::getStatistic(Statistic stat) const {

    return m_statistics.at(stat);

}


void Character::update() {


  
}

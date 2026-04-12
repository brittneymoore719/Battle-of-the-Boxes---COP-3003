#include "Character.h"
#include <SFML/Graphics/Texture.hpp>

//basic constructor for the Box, this is subject to change
Character::Character(
    const std::filesystem::path texturePath,
        double maxHp,
        double currentHp,
        double baseDmg,
        double pierce,
        double defense,
        double dodge,
        double accuracy,
        double critChance,
        double critMultiplier
    ) : texture(texturePath), m_statistics({maxHp, currentHp, baseDmg, pierce, defense, dodge, accuracy, critChance, critMultiplier}) {}


double Character::getStatistic(Statistic stat) const {

    return m_statistics.at(stat);

}


void Character::update() {



}

void Character::takeDamage(double damageAmount) {
    m_statistics[Statistic::CURRENT_HP] -= damageAmount;
}

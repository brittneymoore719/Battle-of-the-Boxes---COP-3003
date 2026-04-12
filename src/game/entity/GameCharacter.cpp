#include "GameCharacter.h"
#include <SFML/Graphics/Texture.hpp>

#include "../combat/actions/GameAction.h"

//basic constructor for the Box, this is subject to change
GameCharacter::GameCharacter(
    const std::filesystem::path& texturePath,
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


double GameCharacter::getStatistic(Statistic stat) const {

    return m_statistics.at(stat);

}


void GameCharacter::update() {



}

void GameCharacter::takeDamage(double damageAmount) {
    m_statistics[Statistic::CURRENT_HP] -= damageAmount;
}

GameAction& GameCharacter::act(GameCharacter& target) {



}

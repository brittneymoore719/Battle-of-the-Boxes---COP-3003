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

bool GameCharacter::isBlocking() const {
    return m_isBlocking;
}

/**
 * @author Ethan Pedrick
 * @param damageAmount amount of damage the character is meant to take
 * @return true if the character is defeated by the damage
 *
 */
bool GameCharacter::takeDamage(double damageAmount) {

    if (damageAmount <= 0) return false;

    m_statistics[CURRENT_HP] -= damageAmount;

    return m_statistics[CURRENT_HP] <= 0;
}

GameAction& GameCharacter::act(GameCharacter& target) {



}

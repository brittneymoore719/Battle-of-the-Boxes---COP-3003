

#ifndef BATTLE_OF_THE_BOXES___COP_3003_CHARACTER_H
#define BATTLE_OF_THE_BOXES___COP_3003_CHARACTER_H
#include <SFML/Graphics/Texture.hpp>
#include <vector>

#include "../GameObject.h"

// to stop it from looping imports
class GameAction;

enum Statistic{MAX_HP, CURRENT_HP, BASE_DMG, PIERCE, DEFENSE, DODGE, ACCURACY, CRIT_CHANCE, CRIT_MULTIPLIER};

class GameCharacter : public GameObject {
    public:

    explicit GameCharacter(
        const std::filesystem::path& texturePath,
        double maxHp = 20.0,
        double currentHp = 20.0,
        double baseDmg = 5.0,
        double pierce = 0.0,
        double defense = 1.0,
        double dodge = 0.0,
        double accuracy = 0.7,
        double critChance = 0.1,
        double critMultiplier = 0.25

        );

    double getStatistic(Statistic stat) const;
    void takeDamage(double damageAmount);

    void update();

    GameAction& act(GameCharacter& target);

private:

    std::vector<double> m_statistics;
    sf::Texture texture;

};

#endif //BATTLE_OF_THE_BOXES___COP_3003_CHARACTER_H

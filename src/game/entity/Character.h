

#ifndef BATTLE_OF_THE_BOXES___COP_3003_CHARACTER_H
#define BATTLE_OF_THE_BOXES___COP_3003_CHARACTER_H
#include <array>
#include <vector>

#include "../GameObject.h"

enum Statistic{MAX_HP, CURRENT_HP, BASE_DMG, PIERCE, DEFENSE, DODGE, ACCURACY, CRIT_CHANCE, CRIT_MULTIPLIER};

class Character : public GameObject {
    public:

    Character(

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

private:

    std::vector<double> m_statistics;

};

#endif //BATTLE_OF_THE_BOXES___COP_3003_CHARACTER_H

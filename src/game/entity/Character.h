

#ifndef BATTLE_OF_THE_BOXES___COP_3003_CHARACTER_H
#define BATTLE_OF_THE_BOXES___COP_3003_CHARACTER_H
#include <array>

#include "../GameObject.h"


class Character : public GameObject {
    public:

    Character();

public:

    std::array<double, 2> getPositionVector();


private:
    void update();
    void takeDame(int amount);
    private:

    std::array<double, 2> m_position;

    double m_health;

};

#endif //BATTLE_OF_THE_BOXES___COP_3003_CHARACTER_H



#ifndef BATTLE_OF_THE_BOXES___COP_3003_CHARACTER_H
#define BATTLE_OF_THE_BOXES___COP_3003_CHARACTER_H
#include "../GameObject.h"


class Character : public GameObject {
    public:

    Character();

    void update();
    void takeDame(int amount);
    private:

    double m_health;

};

#endif //BATTLE_OF_THE_BOXES___COP_3003_CHARACTER_H


#ifndef BATTLE_OF_THE_BOXES___COP_3003_GAMEOBJECT_H
#define BATTLE_OF_THE_BOXES___COP_3003_GAMEOBJECT_H
#include "../display/displayable/Displayable.h"


class GameObject : Displayable {

public:


    GameObject(std::array<double,2> position = {0,0}):

    m_position(position)

    {

    }


    std::array<double, 2> getPositionVector() const {
        return m_position;
    }


private:

    std::array<double, 2> m_position;

};

#endif //BATTLE_OF_THE_BOXES___COP_3003_GAMEOBJECT_H

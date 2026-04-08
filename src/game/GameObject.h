#ifndef BATTLE_OF_THE_BOXES___COP_3003_GAMEOBJECT_H
#define BATTLE_OF_THE_BOXES___COP_3003_GAMEOBJECT_H

#include <array>
#include "../display/displayable/Displayable.h"

class GameObject : public Displayable {
public:
    explicit GameObject(std::array<double, 2> position = {0, 0});
    std::array<double, 2> getPositionVector() const;

private:
    std::array<double, 2> m_position;
};

#endif

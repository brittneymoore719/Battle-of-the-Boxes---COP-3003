
#ifndef BATTLE_OF_THE_BOXES___COP_3003_DISPLAYABLE_H
#define BATTLE_OF_THE_BOXES___COP_3003_DISPLAYABLE_H
#include <array>

#include "../Updatable.h"


class Displayable : Updatable {


public:

    Displayable(bool isDisplayed = false, std::array<double, 2> screenPos = {0.0, 0.0});

    Displayable(Displayable& displayable);

    bool isDisplayed() const;

    void setDisplayed(bool isDisplayed);

    std::array<double,2> getScreenPosition();

    void setScreenPosition(std::array<double,2> position);

private:

    bool m_isDisplayed;

    std::array<double,2> m_screenPosition{}; // where the thing is on the screen


};

#endif //BATTLE_OF_THE_BOXES___COP_3003_DISPLAYABLE_H

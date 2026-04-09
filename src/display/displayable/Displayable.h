#ifndef BATTLE_OF_THE_BOXES___COP_3003_DISPLAYABLE_H
#define BATTLE_OF_THE_BOXES___COP_3003_DISPLAYABLE_H

#include <array>
#include "../Updatable.h"
#include "SFML/Graphics/Image.hpp"

class Displayable : public Updatable {
public:
    Displayable(bool isDisplayed = false, std::array<double, 2> screenPos = {0.0, 0.0});
    Displayable(const Displayable& displayable);

    bool isDisplayed() const;
    void setDisplayed(bool isDisplayed);

    std::array<double, 2> getScreenPosition();
    void setScreenPosition(std::array<double, 2> position);

    const sf::Image getSprite() const;

    void update() override;

private:
    bool m_isDisplayed;
    sf::Image m_sprite{};
    std::array<double, 2> m_screenPosition{};
};

#endif

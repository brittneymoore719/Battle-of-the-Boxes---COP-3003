//
// Created by Ethan Pedrick on 4/4/2026.
//

#include "Displayable.h"

std::array<double, 2> Displayable::getScreenPosition() {
    return m_screenPosition;
}

void Displayable::setScreenPosition(std::array<double, 2> position) {
    m_screenPosition = position;
}

//
// Created by Ethan Pedrick on 4/4/2026.
//

#include "Displayable.h"

Displayable::Displayable(bool isDisplayed, std::array<double, 2> screenPos)
    : m_isDisplayed(isDisplayed), m_screenPosition(screenPos) {}

Displayable::Displayable(const Displayable& displayable)
    : m_isDisplayed(displayable.m_isDisplayed),
      m_screenPosition(displayable.m_screenPosition) {}

bool Displayable::isDisplayed() const {
    return m_isDisplayed;
}

void Displayable::setDisplayed(bool displayed) {
    m_isDisplayed = displayed;
}

std::array<double, 2> Displayable::getScreenPosition() {
    return m_screenPosition;
}

void Displayable::setScreenPosition(std::array<double, 2> position) {
    m_screenPosition = position;
}

const sf::Image Displayable::getSprite() const {
    return m_sprite;
}

void Displayable::update() {
}

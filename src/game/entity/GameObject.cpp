#include "GameObject.h"

GameObject::GameObject(std::array<double, 2> position)
    : m_position(position) {}

std::array<double, 2> GameObject::getPositionVector() const {
    return m_position;
}

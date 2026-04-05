//
// Created by Ethan on 4/4/2026.
//

#include "Stage.h"

#include <utility>

Stage::Stage(std::vector<Displayable> displayables):
    m_displayables(std::move(displayables))
{}

const std::vector<Displayable>& Stage::getDisplayables() const {
    return m_displayables;
}

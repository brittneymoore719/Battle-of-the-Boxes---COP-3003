//
// Created by Ethan on 4/4/2026.
//

#include "Stage.h"

#include <utility>

Stage::Stage(StageType type, std::vector<Displayable> displayables):
    m_type(type),
    m_displayables(std::move(displayables))
{}

StageType Stage::getType() const {
    return m_type;
}

const std::vector<Displayable>& Stage::getDisplayables() const {
    return m_displayables;
}

void Stage::update() {

    ;

}

//
// Created by Ethan on 4/4/2026.
//

#include "Stage.h"

StageType Stage::getType() const {
    return m_type;
}

std::vector<Displayable> Stage::getDisplayables() const {
    return m_displayables;
}

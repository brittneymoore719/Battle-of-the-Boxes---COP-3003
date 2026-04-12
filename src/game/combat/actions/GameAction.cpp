#include "GameAction.h"
#include "game/entity/GameCharacter.h"

GameAction::GameAction(GameCharacter& user, GameCharacter& target):

    m_user(user),
    m_target(target),
    m_name("default")
{}

GameCharacter &GameAction::getTarget() const {
    return m_target;
}

GameCharacter &GameAction::getUser() const {
    return m_user;
}

std::string GameAction::getName() {
    return m_name;
}

void GameAction::setName(const std::string &name) {
    m_name = name;
}

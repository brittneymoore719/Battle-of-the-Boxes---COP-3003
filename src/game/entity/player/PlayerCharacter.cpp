//
// Created by Ethan Pedrick on 4/1/26.
// Updated by Brittney Moore on 4/7/2026

#include "character/PlayerCharacter.h"
#include <iostream>
#include "game/entity/GameCharacter.h"
#include "game/Constants.h"

PlayerCharacter::PlayerCharacter()
    : GameCharacter(
        "sprites/box.png",
        GameConstants::MAX_PLAYER_HEALTH,
        GameConstants::MAX_PLAYER_HEALTH,
        GameConstants::PLAYER_ATTACK_DAMAGE) {}

double PlayerCharacter::getHealth() {
    return getStatistic(Statistic::CURRENT_HP);
}

void PlayerCharacter::handleUserInput() {
    std::cout << "Enter desired action\n"
    << "1. attack\n"
    << "2. dodge\n";
    char choice{0};
    std::cin >> choice;
    choice -= '0';

    m_selectedAction = choice;
}

int PlayerCharacter::getUserAction() {
    return m_selectedAction;
}

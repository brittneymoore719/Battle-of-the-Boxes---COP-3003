//
// Created by Ethan Pedrick on 4/1/26.
//

#include "PlayerCharacter.h"
#include <iostream>
#include "game/entity/Character.h"

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

    if (choice == 2) m_dodged = true;
    else m_dodged = false;

    m_selectedAction = choice;
}

int PlayerCharacter::getUserAction() {
    return m_selectedAction;
}

bool PlayerCharacter::dodged() {
    return m_dodged;
}

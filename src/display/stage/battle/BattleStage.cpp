//
// Created by Ethan Pedrick on 4/5/2026.
//

#include "BattleStage.h"
#include "display/stage/Stage.h"
#include <format>
#include <iostream>
#include "display/stage/title/TitleStage.h"
#include "display/stagecontroller/StageController.h"
#include "game/entity/Character.h"

BattleStage::BattleStage() : Stage() {
    std::cout << "BattleStage initialized\n";
}

void BattleStage::update() {
    std::cout << "BattleStage received update call\n";

    double playerHealth{m_player.getStatistic(Statistic::CURRENT_HP)};
    double enemyHealth{m_enemy.getStatistic(Statistic::CURRENT_HP)};
    std::cout << std::format("player health: {}\nenemy health:{}\n\n", playerHealth, enemyHealth);

    if (enemyHealth <= 0) {
        std::cout << "You won\n"
         << "going back to title\n\n";
         StageController::changeStage(new TitleStage());
         return;
    }
    m_player.handleUserInput();
    int playerAction = m_player.getUserAction();
    if (playerAction < 1 ||playerAction > 2) return;
    if (playerAction == 1) {
        std::cout << "doing player attack\n";
        m_enemy.takeDamage(5);
        std::cout << "enemy has taken 5 damage\n";
    }

    std::cout << "doing enemy attack\n";
    if (!m_player.dodged()) {
        m_player.takeDamage(3);
        std::cout << "player has taken 3 damage\n";
    } else {
        std::cout << "dodged enemy damage\n";
    }

	std::cout << "\n\n";
}

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
#include "game/Constants.h"

BattleStage::BattleStage(CombatSequence& sequence) : Stage(), m_combatSequence(sequence) {
    std::cout << "BattleStage initialized\n";
}

void BattleStage::update() {
    std::cout << "BattleStage received update call\n";

    double playerHealth{m_player.getStatistic(CURRENT_HP)};
    double enemyHealth{m_enemy.getStatistic(CURRENT_HP)};
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
        m_enemy.takeDamage(GameConstants::PLAYER_ATTACK_DAMAGE);
        std::cout << "enemy has taken " << GameConstants::PLAYER_ATTACK_DAMAGE << " damage\n";
    }

    std::cout << "doing enemy attack\n";
    if (!m_player.dodged()) {
        m_player.takeDamage(GameConstants::ENEMY_ATTACK_DAMAGE);
        std::cout << "player has taken " << GameConstants::ENEMY_ATTACK_DAMAGE << " damage\n";
    } else {
        std::cout << "dodged enemy damage\n";
    }

	std::cout << "\n\n";
}

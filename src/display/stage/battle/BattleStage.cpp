//
// Created by Ethan Pedrick on 4/5/2026.
//

#include "BattleStage.h"
#include "display/stage/Stage.h"
#include <format>
#include <iostream>
#include "display/stage/title/TitleStage.h"
#include "display/stagecontroller/StageController.h"
#include "game/entity/GameCharacter.h"
#include "game/Constants.h"

BattleStage::BattleStage(CombatSequence& sequence) : Stage(), m_combatSequence(sequence) {
    std::cout << "BattleStage initialized\n";
}

void BattleStage::update() {
    std::cout << "BattleStage received update call\n";


}

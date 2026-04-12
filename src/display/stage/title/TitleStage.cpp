#include "TitleStage.h"
#include "display/stage/battle/BattleStage.h"
#include "display/stage/Stage.h"
#include "display/stagecontroller/StageController.h"
#include "../../displayable/ui/button/UiButton.h"
#include <iostream>

#include "Game.h"

TitleStage::TitleStage() : Stage(), startButton{"Start Game", {200,200}, {300,150}} {
    std::cout << "TitleStage initialized\n";
}

void TitleStage::update() {
    startButton.update();

    // change stage if start button was pressed
    if (startButton.hasBeenClicked()) {
        std::cout << "changing stage to BattleStage\n";

        Enemy enemy{"Zombie Worker", EnemyType::ZOMBIE_WORKER};

        CombatSequence sequence{Game::getInstance().getPlayer(), enemy};

        BattleStage stage{sequence};

        StageController::changeStage(&stage);
    }
}

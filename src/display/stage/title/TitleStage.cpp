#include "TitleStage.h"
#include "display/stage/battle/BattleStage.h"
#include "display/stage/Stage.h"
#include "display/stagecontroller/StageController.h"
#include "uiElements/UiButton.h"
#include <iostream>

TitleStage::TitleStage() : Stage(), startButton{"Start Game", {200,200}, {300,150}} {
    std::cout << "TitleStage initialized\n";
}

void TitleStage::update() {
    startButton.update();

    // change stage if start button was pressed
    if (startButton.hasBeenClicked()) {
        std::cout << "changing stage to BattleStage\n";
        StageController::changeStage(new BattleStage());
    }
}

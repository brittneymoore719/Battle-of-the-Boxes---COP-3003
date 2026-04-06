#include "TitleStage.h"
#include "display/stage/battle/BattleStage.h"
#include "display/stage/Stage.h"
#include "display/stagecontroller/StageController.h"
#include "uiElements/UiButton.h"
#include <iostream>

TitleStage::TitleStage() : Stage() {
    std::cout << "TitleStage initialized\n";
}

void TitleStage::update() {
    std::cout << "TitleStage received update call\n";

    startButton.update();

    // change stage if start button was pressed
    if (startButton.hasBeenClicked()) {
        std::cout << "changing stage to BattleStage\n";
        StageController::changeStage(new BattleStage());
    }

	std::cout << "\n\n";
}

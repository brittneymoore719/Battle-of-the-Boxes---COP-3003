#include "display/stagecontroller/StageController.h"
#include "display/stage/Stage.h"
#include "display/stage/TitleStage.h"

// defaults to the title stage
Stage* StageController::m_currentStage = new TitleStage();

void StageController::changeStage(Stage* newStage) {
    delete m_currentStage; // free previous stage from memory
    m_currentStage = newStage;
}

void StageController::updateStage() {
    m_currentStage->update();
}

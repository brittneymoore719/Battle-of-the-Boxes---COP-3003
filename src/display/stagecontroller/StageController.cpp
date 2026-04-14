#include "display/stagecontroller/StageController.h"
#include "display/stage/Stage.h"

Stage* StageController::m_currentStage = nullptr;

void StageController::changeStage(Stage* newStage) {
    delete m_currentStage; // free previous stage from memory
    m_currentStage = newStage;
}

void StageController::updateStage() {
    m_currentStage->update();
}

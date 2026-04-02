
#pragma once

#ifndef BATTLE_OF_THE_BOXES_COP_3003_STAGECONTROLLER_H
#define BATTLE_OF_THE_BOXES_COP_3003_STAGECONTROLLER_H
#include "../stage/Stage.h"



// This should be a singleton class
class StageController {

public:

    static StageController getInstance();

private:

    static StageController instance;

    Stage m_currentStage;

    StageController();

};

#endif //BATTLE_OF_THE_BOXES_COP_3003_STAGECONTROLLER_H

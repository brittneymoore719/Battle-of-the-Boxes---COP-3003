#ifndef BATTLE_OF_THE_BOXES_COP_3003_STAGECONTROLLER_H
#define BATTLE_OF_THE_BOXES_COP_3003_STAGECONTROLLER_H
#include "../stage/Stage.h"

class StageController {
public:
    static void changeStage(Stage* newStage);
    static void updateStage();
private:
    static Stage* m_currentStage;
};

#endif //BATTLE_OF_THE_BOXES_COP_3003_STAGECONTROLLER_H

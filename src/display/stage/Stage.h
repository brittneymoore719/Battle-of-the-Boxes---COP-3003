
// These headers were created by CLion automatically
#ifndef BATTLE_OF_THE_BOXES_COP_3003_STAGE_H
#define BATTLE_OF_THE_BOXES_COP_3003_STAGE_H
#include <vector>

#include "display/displayable/Displayable.h"


class Stage : public Updatable {
public:
    virtual ~Stage() = default;
    virtual void update() = 0;
};


#endif //BATTLE_OF_THE_BOXES_COP_3003_STAGE_H

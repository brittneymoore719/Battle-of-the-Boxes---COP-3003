
// These headers were created by CLion automatically
#ifndef BATTLE_OF_THE_BOXES_COP_3003_STAGE_H
#define BATTLE_OF_THE_BOXES_COP_3003_STAGE_H
#include <vector>

#include "display/displayable/Displayable.h"


enum StageType {MENU, LEVEL, BATTLE, SHOPKEEPER};

class Stage { // : Updatable or whatever we decide to name the virtual class that first implements update()

public:

    Stage(StageType type): m_type(type) {}

    StageType getType() const;

    std::vector<Displayable> getDisplayables() const;



private:

    const StageType m_type;

    std::vector<Displayable> m_displayables;

};


#endif //BATTLE_OF_THE_BOXES_COP_3003_STAGE_H

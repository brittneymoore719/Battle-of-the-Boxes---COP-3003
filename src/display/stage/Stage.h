
// These headers were created by CLion automatically
#ifndef BATTLE_OF_THE_BOXES_COP_3003_STAGE_H
#define BATTLE_OF_THE_BOXES_COP_3003_STAGE_H
#include <vector>

#include "display/displayable/Displayable.h"


enum StageType {MENU, LEVEL, BATTLE, SHOPKEEPER};

class Stage : Updatable {

public:
    Stage(StageType type): m_type(type) {}
    virtual ~Stage() = default;

    StageType getType() const;

    const std::vector<Displayable>& getDisplayables() const;

    void update() override;

    virtual void update() = 0;
private:

    StageType m_type;

    std::vector<Displayable> m_displayables;

};


#endif //BATTLE_OF_THE_BOXES_COP_3003_STAGE_H

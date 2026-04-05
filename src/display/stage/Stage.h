
// These headers were created by CLion automatically
#ifndef BATTLE_OF_THE_BOXES_COP_3003_STAGE_H
#define BATTLE_OF_THE_BOXES_COP_3003_STAGE_H
#include <vector>

#include "display/displayable/Displayable.h"


class Stage : public Updatable {

public:
    explicit Stage(std::vector<Displayable> displayables);
    virtual ~Stage() = default;

    virtual void update() = 0;

    const std::vector<Displayable>& getDisplayables() const;

private:

    std::vector<Displayable> m_displayables;

};


#endif //BATTLE_OF_THE_BOXES_COP_3003_STAGE_H

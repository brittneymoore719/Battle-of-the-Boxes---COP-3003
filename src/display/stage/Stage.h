
// These headers were created by CLion automatically
#ifndef BATTLE_OF_THE_BOXES_COP_3003_STAGE_H
#define BATTLE_OF_THE_BOXES_COP_3003_STAGE_H
#include <vector>

#include "display/displayable/Displayable.h"


class Stage : public Updatable {

public:
    explicit Stage(std::vector<Displayable> displayables);
    virtual ~Stage() = default;

    const std::vector<Displayable>& getDisplayables() const;

    void update() override;

private:

    std::vector<Displayable> m_displayables;

};


#endif //BATTLE_OF_THE_BOXES_COP_3003_STAGE_H

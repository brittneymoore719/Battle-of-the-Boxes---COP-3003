
// These headers were created by CLion automatically
#ifndef BATTLE_OF_THE_BOXES_COP_3003_STAGE_H
#define BATTLE_OF_THE_BOXES_COP_3003_STAGE_H

#endif //BATTLE_OF_THE_BOXES_COP_3003_STAGE_H

enum StageType {MENU, LEVEL, BATTLE, SHOPKEEPER};

class Stage { // : Updatable or whatever we decide to name the virtual class that first implements update()

public:

    Stage(StageType type): m_type(type) {}

    StageType getType() const {
        return m_type;
    }

private:

    StageType m_type;

};
#include "game/combat/Action.h"

class BasicAttack : public Action {
    public:
    BasicAttack(std::string name);
    virtual void onUse(Character& user, Character& target) override;
};

#include "../GameAction.h"

class BasicAttack : public GameAction {
    public:
    BasicAttack(GameCharacter& user, GameCharacter& target);

    bool apply() override;
};

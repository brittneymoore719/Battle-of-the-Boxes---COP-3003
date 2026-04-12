#include "../Card.h"

class BasicAttack : public Card {
    public:
    BasicAttack();
    virtual void use(Character& user, Character& target) override;
};

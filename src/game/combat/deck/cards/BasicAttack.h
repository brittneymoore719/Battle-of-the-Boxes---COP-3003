#ifndef BASICATTACK_H
#define BASICATTACK_H

#include "../Card.h"

class BasicAttack : public Card {
    public:
    BasicAttack();
    bool use(Character& user, Character& target) override;
};

#endif

#ifndef BASICATTACK_H
#define BASICATTACK_H

#include "../Card.h"

class BasicAttack : public Card {
    public:
    BasicAttack();
    void use(Character& user, Character& target) override;
};

#endif

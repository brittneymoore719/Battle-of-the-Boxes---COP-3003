#ifndef BLOCK_H
#define BLOCK_H

#include "../Card.h"

class Block : public Card {
    public:
    Block();
    void use(Character& user, Character& target) override;
};

#endif

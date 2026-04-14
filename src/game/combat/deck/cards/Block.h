#ifndef BLOCK_H
#define BLOCK_H

#include "../Card.h"

class Block : public Card {
    public:
    Block();
    bool use(Character& user, Character& target) override;
};

#endif

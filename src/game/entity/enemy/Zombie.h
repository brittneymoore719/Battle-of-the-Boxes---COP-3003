#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "game/entity/enemy/Enemy.h"
class Zombie : public Enemy {
    public:
        Zombie(int position);
        void attack(Character& target) override;
    private:
};

#endif

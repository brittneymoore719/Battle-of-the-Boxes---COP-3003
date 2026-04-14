#include "Block.h"
#include <format>
#include <iostream>
#include <string>

#include "game/entity/Character.h"
#include "game/entity/stats/HealthPool.h"

Block::Block(): Card("Block", "block 5\ndamage") {

}

void Block::use(Character& user, Character& target) {
    HealthPool& targetHealthPool = target.getHealthPool();
    targetHealthPool.addBlock(5);
}

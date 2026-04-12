#include "Block.h"
#include <format>
#include <iostream>
#include <string>

Block::Block(): Card("Block", "block 5 damage") {

}

void Block::use(Character& user, Character& target) {
    HealthPool& targetHealthPool = target.getHealthPool();
    targetHealthPool.addBlock(5);
}

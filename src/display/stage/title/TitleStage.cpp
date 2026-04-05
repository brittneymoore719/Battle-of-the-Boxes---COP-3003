#include "TitleStage.h"
#include "display/stage/Stage.h"
#include <iostream>

TitleStage::TitleStage() : Stage({}) {
    std::cout << "TitleStage initialized\n";
}

void TitleStage::update() {
    std::cout << "TitleStage received update call\n";
}

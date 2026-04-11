//
// Created by Ethan Pedrick on 4/11/2026.
//

#include "RNG.h"

RNG &RNG::getInstance() {
    return instance;
}

int RNG::getRandomNumber(int min, int max) {

    std::uniform_int_distribution<int> distribution(min, max);

    return distribution(m_engine);

}

bool RNG::roll(int probability) {

    if (probability <= 0) return false;
    if (probability >= 100) return true;

    return getRandomNumber(1, 100) <= probability;

}

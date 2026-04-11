//
// Created by Ethan Pedrick on 4/11/2026.
//

#ifndef BATTLE_OF_THE_BOXES_RNG_H
#define BATTLE_OF_THE_BOXES_RNG_H
#include <random>

class RNG {

public:

    RNG& getInstance();

    int getRandomNumber(int min, int max);

    bool roll(int probability);



private:

    RNG() = default;
    static RNG& instance;

    std::random_device m_device;
    std::mt19937 m_engine{m_device()}; // This was recommended by google as a higher quality engine


};


#endif //BATTLE_OF_THE_BOXES_RNG_H
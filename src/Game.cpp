#include "Game.h"

#include <iostream>

#include "game/entity/player/PlayerCharacter.h"
#include "SFML/Graphics/RenderWindow.hpp"

// if we truly want a Game object it should be a singleton

Game Game::instance{};

Game::Game() : m_player(PlayerCharacter()) {
}

void Game::start(){
    std::cout << "Game starting..." << std::endl;
}

PlayerCharacter &Game::getPlayer() {
    return m_player;
}

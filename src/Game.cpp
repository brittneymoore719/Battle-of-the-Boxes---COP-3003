#include <iostream>

#include "SFML/Graphics/RenderWindow.hpp"

// if we truly want a Game object it should be a singleton

class Game{
public:

  static Game& getInstance() {
    return instance;
  }

  void start(){
    std::cout << "Game starting..." << std::endl;
  }

private:

  static Game instance;

  sf::RenderWindow renderWindow{sf::VideoMode({800, 600}), "Battle of the Boxes"};

};

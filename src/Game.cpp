#include <iostream>

// if we truly want a Game object it should be a singleton

class Game{
public:

  static Game getInstance() {
    return instance;
  }

  void start(){
    std::cout << "Game starting..." << std::endl;
  }

private:

  static Game instance;

  Game() = default;

};

//todo add in main game loop and box logic

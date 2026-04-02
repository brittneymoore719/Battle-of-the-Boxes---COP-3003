#ifndef UIELEMENTBASE_H
#define UIELEMENTBASE_H
#include "Displayable.h"
#include <SFML/Graphics.hpp>

class UiElementBase:public Displayable
{
public:
  virtual void update(float deltaTime);
  virtual void draw(sf::RenderWindow& window) = 0;

};

#endif // UIELEMENTBASE_H

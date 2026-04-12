#ifndef UIELEMENTBASE_H
#define UIELEMENTBASE_H

#include <SFML/Graphics.hpp>
#include "display/displayable/Displayable.h"

class UiElementBase : public Displayable
{
public:

  virtual void update(float deltaTime);

  virtual void draw(sf::RenderWindow& window) = 0;

};

#endif // UIELEMENTBASE_H

#ifndef UIELEMENTBASE_H
#define UIELEMENTBASE-H
#include "Displayable.h"
#endif

class UiElementBase:public Displayable
{
public: 
  virtual void update(float deltaTime)
  virtual void draw(sf::RenderWindow& window)override=0;

}

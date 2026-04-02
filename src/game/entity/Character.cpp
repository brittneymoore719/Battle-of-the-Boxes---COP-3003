#include "Character.h"

//basic constructor for the Box, this is subject to change
Character::Character()
{
  m_health=100;
}

//possible logic for combat with the warehouse workers/other mobs
void Character::takeDamage(double damage)
{
  m_health -= damage;
  if (m_health<0) m_health=0;
}

//possible loigc for player movement
void Character::update()
{

  //WASD keyboard movement and many on screen movement will have its logic handled here later.
  
}

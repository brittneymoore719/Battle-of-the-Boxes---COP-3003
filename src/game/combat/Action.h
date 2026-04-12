#include "game/entity/Character.h"
class Action {
    public:
    Action(std::string name);
    virtual void onUse(Character& user, Character& target) = 0;

    private:
    std::string m_name;
    //sf::Texture icon; // if we want some kind of icon for each move
};


#ifndef GAMEACTION
#define GAMEACTION

#pragma once
#include "game/GameObject.h"

class GameCharacter;

class GameAction {

    public:

    virtual ~GameAction() = default;

    GameAction(GameCharacter& user, GameCharacter& target);

    GameCharacter& getUser() const;

    GameCharacter& getTarget() const;

    std::string getName();

    void setName(const std::string &name);


    virtual void apply() = 0;

    private:

    std::string m_name;

    GameCharacter& m_user;
    GameCharacter& m_target;
    //sf::Texture icon; // if we want some kind of icon for each move
};

#endif

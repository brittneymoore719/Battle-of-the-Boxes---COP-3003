//
// Created by Ethan Pedrick on 4/13/26.
// edited by Brittney Moore on 4/15/2026

#include "CombatSequence.h"

#include <iostream>

#include "game/entity/enemy/Enemy.h"
#include "game/entity/player/PlayerCharacter.h"

CombatSequence::CombatSequence(std::vector<std::unique_ptr<Enemy> > enemies,
std::unique_ptr<PlayerCharacter> player) :
    m_player(std::move(player)),
    m_enemies(std::move(enemies)),
    m_state(CombatState::ONGOING) {

    std::cout << "CombatSequence initialized";

}

CombatState CombatSequence::getState() const {
    return m_state;
}

std::unique_ptr<PlayerCharacter>& CombatSequence::getPlayer() {
    return m_player;
}

std::vector<std::unique_ptr<Enemy>> &CombatSequence::getEnemies() {
    return m_enemies;
}

void CombatSequence::update() {

    bool m_allEnemiesDead = true;

    for (const auto& enemy : m_enemies) {
        if (!enemy->getHealthPool().isDead()) {
            m_allEnemiesDead = false;
        }
    }

    if (m_allEnemiesDead)
    {

        m_state = CombatState::PLAYER_WON;

    }

    if (m_player->getHealthPool().isDead()) {

        m_state = CombatState::PLAYER_LOST;

    }

    if (m_state != ONGOING) {


        return;
    }

}

//
// Created by Ethan Pedrick on 4/5/2026.
//

#ifndef BATTLE_OF_THE_BOXES_BATTLESTAGE_H
#define BATTLE_OF_THE_BOXES_BATTLESTAGE_H

#include <vector>
#include <memory>
#include "deck/Deck.h"
#include "display/stage/Stage.h"
#include "../../../game/entity/player/PlayerCharacter.h"
#include "game/entity/enemy/Enemy.h"


class BattleStage : public Stage {
public:
    // Default constructor: creates one default enemy and a default player
    BattleStage();

    // Constructor taking ownership of enemies and player via unique_ptr
    BattleStage(std::vector<std::unique_ptr<Enemy>> enemies,
                std::unique_ptr<PlayerCharacter> player);

    virtual ~BattleStage() = default;

    bool isCharacterHovered();

    virtual void update() override;

private:
    std::unique_ptr<PlayerCharacter> m_player;
    std::vector<std::unique_ptr<Enemy>> m_enemies;
    Deck m_deck;
    int m_selectedCard;

    Enemy& m_hoveredEnemy;
    bool m_playerHovered;
};

#endif //BATTLE_OF_THE_BOXES_BATTLESTAGE_H

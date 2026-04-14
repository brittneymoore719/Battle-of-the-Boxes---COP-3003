//
// Created by Ethan Pedrick on 4/5/2026.
//

#ifndef BATTLE_OF_THE_BOXES_BATTLESTAGE_H
#define BATTLE_OF_THE_BOXES_BATTLESTAGE_H

#include <vector>
#include <memory>
#include <SFML/Graphics/Text.hpp>
#include "display/stage/Stage.h"
#include "../../../game/entity/player/PlayerCharacter.h"
#include "game/combat/CombatSequence.h"
#include "game/combat/deck/Deck.h"
#include "game/entity/enemy/Enemy.h"


class BattleStage : public Stage {
public:
    BattleStage(std::unique_ptr<CombatSequence> sequence);

    virtual ~BattleStage() = default;

    bool isCharacterHovered();

    void update() override;

private:

    std::unique_ptr<CombatSequence> m_sequence;

    int m_selectedCard;

    Enemy* m_hoveredEnemy;
    bool m_playerHovered;
    bool m_allEnemiesDead;
    bool m_playerDead;
    int m_cardsPlayed;
    sf::Text m_drawCounterText;
    void updateDrawCounterDisplay();
    void refreshHand();

    bool m_wasMousePressed;   // added to prevent actions from repeating when the mouse is held down
};

#endif //BATTLE_OF_THE_BOXES_BATTLESTAGE_H

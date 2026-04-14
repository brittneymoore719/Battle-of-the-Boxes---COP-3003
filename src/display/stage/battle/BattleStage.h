//
// Created by Ethan Pedrick on 4/5/2026.
//

#ifndef BATTLE_OF_THE_BOXES_BATTLESTAGE_H
#define BATTLE_OF_THE_BOXES_BATTLESTAGE_H

#include <vector>
#include <memory>
#include <SFML/Graphics/Text.hpp>
#include "deck/Deck.h"
#include "display/stage/Stage.h"
#include "../../../game/entity/player/PlayerCharacter.h"
#include "game/entity/enemy/Enemy.h"
#include "display/displayable/ui/button/UiButton.h"


class BattleStage : public Stage {
public:
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

    Enemy* m_hoveredEnemy;
    bool m_playerHovered;
    bool m_allEnemiesDead;
    bool m_playerDead;
    int m_cardsPlayed;
    sf::Text m_drawCounterText;
    UiButton m_menuButton;
    UiButton m_exitButton;
    bool m_menuOpen;
    void updateDrawCounterDisplay();
    void refreshHand();

    bool m_wasMousePressed;   // added to prevent actions from repeating when the mouse is held down
};

#endif //BATTLE_OF_THE_BOXES_BATTLESTAGE_H

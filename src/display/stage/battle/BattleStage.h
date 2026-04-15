//
// Created by Ethan Pedrick on 4/5/2026.
// edited by Brittney Moore 4/14/2026

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
#include "display/displayable/ui/button/UiButton.h"
#include<optional>

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
    std::optional<sf::Texture> m_backgroundTexture;
    std::optional<sf::Sprite> m_backgroundSprite;
    UiButton m_menuButton;
    UiButton m_exitButton;
    bool m_menuOpen;
    void updateDrawCounterDisplay();
    void refreshHand();

    bool m_wasMousePressed;   // added to prevent actions from repeating when the mouse is held down
    
    //for the trash can
    //attempt at disguard button with trash image, trouble shoot with late
    // std::optional<sf::Texture> m_trashTexture;
    //std::optional<sf::Sprite> m_trashSprite;
    UiButton m_discardButton;

    //for pass button
    UiButton m_passButton;
};

#endif //BATTLE_OF_THE_BOXES_BATTLESTAGE_H

#ifndef TURNMANAGER_H
#define TURNMANAGER_H

#include <SFML/Graohics/Text.hpp>
#include "CombatSequence.h"
#include "deck/Deck.h"

class TurnManager {
   public:
    TurnManager(CombatSequence& sequence);

    void onCardPlayed(std::shared_ptr<Card> card);
    void passTurn();
    void updateDisplay();
    sf::Text& getDrawCounterText();

    private:
    CombatSequence& m_sequence;
     int m_cardsPlayed;
    sf::Text m_drawCounterText;

    void refreshHand();
    void endPlayerTurn();
    void updateDrawCounterDisplay();

};









#endif // TURNMANAGER_H
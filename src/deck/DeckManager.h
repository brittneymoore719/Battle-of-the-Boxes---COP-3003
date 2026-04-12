#ifndef DECKMANAGER_H
#define DECKMANAGER_H

#include <memory>
#include <vector>
#include "Card.h"
#include "Deck.h"

class DeckManager {
    public:
    static Deck createDeck();
    static std::vector<std::shared_ptr<Card>>& getCards();

    private:
    static std::vector<std::shared_ptr<Card>> m_cards;
};

#endif

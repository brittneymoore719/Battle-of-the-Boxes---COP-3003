#ifndef DECK_H
#define DECK_H

#include <memory>
#include <queue>
#include <vector>
#include "Card.h"

class Deck {
public:
    explicit Deck(std::vector<std::shared_ptr<Card>>& cards);
    void activateCards(int numCards);
    void deactivateCard(std::shared_ptr<Card> card);
    std::vector<std::shared_ptr<Card>>& getCards();

    // New methods for hand refresh
    size_t getInactiveCount() const;
    void reshuffleDiscard();

private:
    std::queue<std::shared_ptr<Card>> m_inactiveCards;
    std::vector<std::shared_ptr<Card>> m_activeCards;
};

#endif

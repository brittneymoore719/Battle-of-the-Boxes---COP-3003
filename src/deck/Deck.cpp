#include "Deck.h"
#include <memory>

Deck::Deck(std::vector<std::shared_ptr<Card>>& cards) {
    for (auto& card : cards) {
        m_inactiveCards.push(card);
    }
}

void Deck::activateCards(int numCards) {
    for (int i = 0; i < numCards; ++i) {
        m_activeCards.push_back(m_inactiveCards.front());
        m_inactiveCards.pop();
    }
}

void Deck::deactivateCard(std::shared_ptr<Card> card) {
    m_inactiveCards.push(card);
    std::erase(m_activeCards, card);
}

std::vector<std::shared_ptr<Card>>& Deck::getCards() {
    return m_activeCards;
}

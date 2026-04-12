#include "Deck.h"
#include <algorithm>
#include <random>
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

size_t Deck::getInactiveCount() const {
    return m_inactiveCards.size();
}

void Deck::reshuffleDiscard() {
    if (m_inactiveCards.empty()) return;

    std::vector<std::shared_ptr<Card>> discard;
    while (!m_inactiveCards.empty()) {
        discard.push_back(m_inactiveCards.front());
        m_inactiveCards.pop();
    }

    static std::random_device rd;
    static std::default_random_engine g(rd());
    std::shuffle(discard.begin(), discard.end(), g);

    for (auto& card : discard) {
        m_inactiveCards.push(card);
    }
}

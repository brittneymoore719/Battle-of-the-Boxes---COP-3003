#include "DeckManager.h"
#include <algorithm>
#include <iostream>
#include <memory>
#include <random>
#include "cards/BasicAttack.h"
#include "cards/Block.h"

std::vector<std::shared_ptr<Card>> DeckManager::m_cards = {std::make_shared<BasicAttack>(), std::make_shared<BasicAttack>(), std::make_shared<BasicAttack>(), std::make_shared<BasicAttack>(), std::make_shared<Block>(), std::make_shared<Block>(), std::make_shared<Block>(), std::make_shared<Block>()};

std::vector<std::shared_ptr<Card>>& DeckManager::getCards() {
    return m_cards;
}

Deck DeckManager::createDeck() {
    static std::random_device rd;
    static std::default_random_engine g(rd());

    std::shuffle(m_cards.begin(), m_cards.begin(), g);
    return Deck(m_cards);
}

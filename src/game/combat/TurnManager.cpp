#include "TurnManager.h"
#include "WindowManager.h"
#include "game/entity/enemy/Enemy.h"
#include "game/entity/player/PlayerCharacter.h"

TurnManager::TurnManager(CombatSequence& sequence)
	: m_sequence(sequence),
	m_cardsPlayed(0),
	m_drawCounterText(WindowManager::getFont())
{
	m_drawCounterText.setFont(WindowManager::getFont());
	m_drawCounterText.setCharacterSize(20);
	m_drawCounterText.setFillColor(sf::Color::White);
	m_drawCounterText.setPosition({10.f, 10.f});
    updateDrawCounterDisplay();
}

void TurnManager::updateDrawCounterDisplay() { 
	int remaining = 3 - (m_cardsPlayed % 3);
    m_drawCounterText.setString("actions left: " + std::to_string(remaining));
}

sf::Text& TurnManager::getDrawCounterText() {
	return m_drawCounterText; 
}

void TurnManager::updateDisplay() {
	updateDrawCounterDisplay(); 
}

void TurnManager::refreshHand() { 
	m_sequence.getPlayer()->getDeck().reshuffleDiscard();
	m_sequence.getPlayer()->getDeck().activateCards(8);
}

void TurnManager::endPlayerTurn() {
	refreshHand();
    for (auto& enemy : m_sequence.getEnemies()) {
            enemy->attack(*m_sequence.getPlayer());
    }
}

//function for passturn
void TurnManager::passTurn() { endPlayerTurn(); }

void TurnManager::onCardPlayed(std::shared_ptr<Card> card) {
    m_cardsPlayed += 1;
	if (m_cardsPlayed % 3 == 0) {
		endPlayerTurn();
	}
        updateDrawCounterDisplay();
}
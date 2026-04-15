#include "TurnManager.h"
#include "WindowManager.h"
#include "game/entity/enemy/Enemy.h"

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
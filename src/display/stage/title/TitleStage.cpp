#include "TitleStage.h"
#include "display/stage/battle/BattleStage.h"
#include "display/stage/Stage.h"
#include "display/stagecontroller/StageController.h"
#include "../../displayable/ui/button/UiButton.h"
#include "game/Constants.h"
#include "game/entity/enemy/Zombie.h"
#include "WindowManager.h"
#include <iostream>
#include <memory>
#include <vector>
#include "game/combat/CombatSequence.h"
#include <SFML/Window/Mouse.hpp>

TitleStage::TitleStage()
    : Stage(),
      startButton{"Start Game",
                  {GameConstants::WINDOW_WIDTH / 2.f, GameConstants::WINDOW_HEIGHT / 2.f},
                  {300.f, 80.f}},
      exitButton{"Exit",
                 {GameConstants::WINDOW_WIDTH / 2.f, GameConstants::WINDOW_HEIGHT / 2.f + 120.f},
                 {300.f, 80.f}}
{
    m_nameBox.setSize({300.f, 40.f});
    m_nameBox.setPosition(
        {GameConstants::WINDOW_WIDTH / 2.f - 150.f, GameConstants::WINDOW_HEIGHT / 2.f - 100.f});
    m_nameBox.setFillColor(sf::Color::White);
    m_nameBox.setOutlineColor(sf::Color::Black);
    m_nameBox.setOutlineThickness(2.f);

    m_nameLabel.reset(new sf::Text(WindowManager::getFont()));
    m_nameLabel->setCharacterSize(18);
    m_nameLabel->setFillColor(sf::Color::White);
    m_nameLabel->setString("Enter your name:");
    m_nameLabel->setPosition(
        {GameConstants::WINDOW_WIDTH / 2.f - 150.f, GameConstants::WINDOW_HEIGHT / 2.f - 130.f});

    m_nameText.reset(new sf::Text(WindowManager::getFont()));
    m_nameText->setFillColor(sf::Color::Black);
    m_nameText->setPosition(
        {GameConstants::WINDOW_WIDTH / 2.f - 140.f, GameConstants::WINDOW_HEIGHT / 2.f - 95.f});

    m_nameBoxActive = false;

    std::cout << "TitleStage initialized\n";
}

void TitleStage::update() 
{
    
    sf::RenderWindow& window = WindowManager::getWindow();
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        sf::Vector2f mousePos = WindowManager::getMousePos();
        m_nameBoxActive = m_nameBox.getGlobalBounds().contains(mousePos);
    }
    if (m_nameBoxActive) {
        m_playerName = WindowManager::getTypedInput().toAnsiString();
        m_nameBox.setOutlineColor(sf::Color::Blue);
    } else {
        m_nameBox.setOutlineColor(sf::Color::Black);
    }

    m_nameText->setString(m_playerName);
    window.draw(*m_nameLabel);
    window.draw(m_nameBox);
    window.draw(*m_nameText);

    startButton.update();
    exitButton.update();

    if (startButton.hasBeenClicked()) {
        std::cout << "changing stage to BattleStage\n";

        std::vector<std::unique_ptr<Enemy>> enemies;
        enemies.push_back(std::make_unique<Zombie>(1));
        auto player = std::make_unique<PlayerCharacter>();
        if (!m_playerName.empty()) 
        {
            player->setName(m_playerName);
        }

        auto sequence = std::make_unique<CombatSequence>(std::move(enemies), std::move(player));

        StageController::changeStage(new BattleStage(std::move(sequence)));
    }

   else if (exitButton.hasBeenClicked()) {
        WindowManager::getWindow().close();
    }
}

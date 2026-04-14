#include "TitleStage.h"
#include "display/stage/battle/BattleStage.h"
#include "display/stage/Stage.h"
#include "display/stagecontroller/StageController.h"
#include "../../displayable/ui/button/UiButton.h"
#include "game/Constants.h"
#include "game/entity/enemy/Zombie.h"
#include <iostream>
#include <memory>
#include <vector>
#include "WindowManager.h"

TitleStage::TitleStage() : Stage(), startButton{"Start Game", {GameConstants::WINDOW_WIDTH / 2.f, GameConstants::WINDOW_HEIGHT / 4.f * 3.f}, {GameConstants::WINDOW_WIDTH / 2.f,GameConstants::WINDOW_HEIGHT / 4.f}} 
  {GameConstants::WINDOW_WIDTH / 2.f, GameConstants::WINDOW_HEIGHT / 4.f}},
      exitButton{"Exit", {GameConstants::WINDOW_WIDTH / 2.f, GameConstants::WINDOW_HEIGHT / 4.f * 3.f + 80.f},
{
    std::cout << "TitleStage initialized\n";
}

void TitleStage::update() {
    startButton.update();

    // change stage if start button was pressed
    if (startButton.hasBeenClicked()) {
        std::cout << "changing stage to BattleStage\n";
        std::vector<std::unique_ptr<Enemy>> enemies;
        enemies.push_back(std::make_unique<Zombie>(1));

        auto player = std::make_unique<PlayerCharacter>();


        StageController::changeStage(new BattleStage(std::move(enemies), std::move(player)));
    }

    if (exitButton.hasBeenClicked()) 
    {
        WindowManager::getWindow().close();
    }
}

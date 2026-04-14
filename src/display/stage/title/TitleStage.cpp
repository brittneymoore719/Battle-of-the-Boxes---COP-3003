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

TitleStage::TitleStage()
    : Stage(),
      startButton{"Start Game",
                  {GameConstants::WINDOW_WIDTH / 2.f, GameConstants::WINDOW_HEIGHT / 2.f},
                  {300.f, 80.f}},
      exitButton{"Exit",
                 {GameConstants::WINDOW_WIDTH / 2.f, GameConstants::WINDOW_HEIGHT / 2.f + 120.f},
                 {300.f, 80.f}}
{
    std::cout << "TitleStage initialized\n";
}

void TitleStage::update() {
    startButton.update();
    exitButton.update();

    if (startButton.hasBeenClicked()) {
        std::cout << "changing stage to BattleStage\n";
        std::vector<std::unique_ptr<Enemy>> enemies;
        enemies.push_back(std::make_unique<Zombie>(1));
        auto player = std::make_unique<PlayerCharacter>();

        StageController::changeStage(new BattleStage(std::move(enemies), std::move(player)));
    }

   else if (exitButton.hasBeenClicked()) {
        WindowManager::getWindow().close();
    }
}

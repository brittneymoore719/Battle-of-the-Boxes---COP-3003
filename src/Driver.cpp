#include <SFML/Graphics/RenderWindow.hpp>
#include "display/stagecontroller/StageController.h"
#include "WindowManager.h"




int main() {
    sf::RenderWindow& window = WindowManager::getWindow();

	while ( window.isOpen() )
	{
        WindowManager::handleEvents();


        window.clear();

	    // update current stage
		StageController::updateStage();

		window.display();
	}
    return 0;
}

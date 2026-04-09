#include "display/stage/Stage.h"
#include "display/stage/title/TitleStage.h"
#include "display/stagecontroller/StageController.h"
#include <iostream>
#include <string>




int main() {
    std::cout << "Starting main game loop\n";
	while ( true )
	{
	    // update current stage
		StageController::updateStage();
	}
    return 0;
}

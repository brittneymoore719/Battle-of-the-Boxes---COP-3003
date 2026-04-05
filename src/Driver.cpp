#include "display/stage/Stage.h"
#include "display/stage/TitleStage.h"
#include "display/stagecontroller/StageController.h"
#include <iostream>
#include <string>
int main() {

	while ( true )
	{
	    std::cout << "select an option:\n"
					<< "1. quit\n"
					<< "2. update current Stage\n"
					<< "3. change current Stage\n";
	    int choice{0};
	    std::cin >> choice;
		std::cout << "\n";
		if (choice == 1) break;
		if (choice == 2) StageController::updateStage();
		if (choice == 3) {
		    std::cout << "Select Stage to change to\n"
						<< "1. Title\n";
			int stageChoice{0};
			std::cin >> stageChoice;
			std::cout << "\n";
			switch (stageChoice) {
			case 1:
    			StageController::changeStage(new TitleStage());
    			break;
			}
		}

		std::cout << "\n\n";
	}
    return 0;
}

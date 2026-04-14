#include <SFML/Graphics/RenderWindow.hpp>
#include "display/stage/title/TitleStage.h"
#include "display/stagecontroller/StageController.h"
#include "WindowManager.h"
#include <iostream>
#include <filesystem>


// sfml asset loading is done relative to the current working directory so we need to set it to the exe's directory
// a caveat of this is that you can't statically declare anything that needs to load a file
// we could have a static variable call this function before including any other files to get around this if its important
// but thats a very hacky solution and probably better to avoid
void setCWD(char* exePath) {
    try {
            // get directory of exe
            std::filesystem::path exeDir = std::filesystem::absolute(exePath).parent_path();

            // set the current working directory
            std::filesystem::current_path(exeDir);

            std::cout << "CWD set to: " << std::filesystem::current_path() << "\n";
        } catch (const std::filesystem::filesystem_error& e) {
            std::cerr << "Error setting CWD: " << e.what() << "\n";
        }

}

int main(int argc, char* argv[]) {
    setCWD(argv[0]);
    WindowManager::createWindow();
    sf::RenderWindow& window = WindowManager::getWindow();
    StageController::changeStage(new TitleStage());
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

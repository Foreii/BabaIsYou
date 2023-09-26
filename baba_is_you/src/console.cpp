#include "console.h"
#include "controller.h"

//#include "direction.h"

#include <cstdlib>

using namespace view;

Console::Console(model::Facade & game, controller::Controller* controller):game_{game}, controller_{controller}{
    game_.addObserver(this);

}

void Console::showMessage(std::string msg) {
    std::cout << "===========================================" << std::endl;
    std::cout << msg << std::endl;
    std::cout << "===========================================" << std::endl;
}

void Console::showHelp() {
    std::cout << "============" << std::endl;
    std::cout << "  Commands " << std::endl;
    std::cout << "============" << std::endl;
    std::cout << " - restart : restart the game." << std::endl;
    std::cout << " - save : save the actual state of the game." << std::endl;
    std::cout << " - load save [x] : load the saved game for level x." << std::endl;
    std::cout << " - quit : exit the game." << std::endl;
}

void Console::showLevel() {
    showHeader();

}

void Console::showHeader() {
    std::cout << "===============================================================================================================" << std::endl;
    std::cout << "Level " << game_.getLevel() << "                                      " << "BABA IS YOU" << std::endl;

//    for (int i = 0; i < game_.getMapWidth(); i++) {
//        std::cout << "=====";
//    }
    std::cout << "===============================================================================================================" << std::endl;
//    std::cout << std::endl;
}

//std::string Console::treatCommand() {

//    return str;
//}

void Console::treatInput() {
    bool stop = false;

    std::string str;
    do {
        this->showMessage("Please enter a command [ help for more info ]");
        std::getline(std::cin, str);

        stop = this->controller_->treatInput(str);

    } while(!stop);

}


void Console::update() {
    showLevel();
    std::cout << game_.getMapRepresentation() << std::endl;
}

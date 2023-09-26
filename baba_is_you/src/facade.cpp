#include "facade.h"

using namespace model;

Facade::Facade(int level):game_(level) {}

void Facade::movePlayer(std::string dir) {

    char direction = std::toupper(dir[0]);

    switch(direction){
        case 'S': {
            game_.movePlayer(model::Direction::DOWN);
            break;
        }
        case 'Z': {
            game_.movePlayer(model::Direction::UP);

            break;
        }
        case 'D': {
            game_.movePlayer(model::Direction::RIGHT);

            break;
        }
        case 'Q': {
            game_.movePlayer(model::Direction::LEFT);

            break;
        }
        default: throw std::invalid_argument("This is not a possible direction!");
    }
}

void Facade::start() {
    game_.start();
}

std::string Facade::getMapRepresentation() {
    return game_.getMapRepresentation();
}

int Facade::getMapWidth() {
    return game_.getMapWidth();
}

int Facade::getLevel() {
    return game_.getLevel();
}

bool Facade::getGameState() {
    return game_.getGameState();
}

std::multimap<Position, Tile> Facade::getMap() {
    return game_.getMap().getMap();
}

void Facade::nextLevel() {
    game_.nextLevel(game_.getLevel());
}

void Facade::saveGame() {
    game_.saveGame(game_.getLevel());
}

void Facade::loadLevel(int level) {
    game_.loadLevel(level);
}

void Facade::loadSavedLevel(int num) {
    game_.loadSavedLevel(num);
}

void Facade::addObserver(util::Observer* observer) {
    game_.addObserver(observer);
}

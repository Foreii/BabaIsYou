#include "game.h"

using namespace model;

Game::Game(int level): currentLevel_{level}, map_{currentLevel_}, observers_{std::set<util::Observer*>()} {
    initializeRules();
    findPlayer();
}

bool Game::getGameState() {
    return wonLevel_;
}

bool Game::isGameLost() {
    return isLost_;
}

int Game::getMapWidth() {
    return map_.getWidth();
}

int Game::getLevel() {
    return map_.getLevel();
}

const model::Map& Game::getMap() const {
    return map_;
}

void Game::initializeRules() {
    map_.initializeRules(listRules_);
}

void Game::findPlayer() {
    playerBlocks_.clear();
    for (auto const & rule : listRules_) {
        Block textRule = rule.second.getBlock();

        std::cout << rule.first.getBlock() << std::endl;
        std::cout << rule.second.getBlock() << std::endl;

        if (textRule == Block::YOU) {
            playerBlocks_ = map_.findBlock(rule.first);
            return;
        }
    }
}

void Game::move(Tile & tile, Direction dir) {
    Position tilePos = tile.getPosition();
    Position nextPos = tilePos.next(dir);

    Tile nextTile;

    if (map_.isInMap(nextPos)) {
        Tile nextTile = map_.getTile(nextPos);

        if(nextTile.getBlockType() == BlockType::IS
                    || nextTile.getBlockType() == BlockType::TEXT
                    || nextTile.getBlockType() == BlockType::RULE) {

            move(nextTile, dir);

            if(nextTile.getPosition() != tile.getPosition().next(dir)) {
                map_.moveTile(tile, dir);
            }
            initializeRules();
            transformBlock();
        } else {
            Block nextBlock = nextTile.getBlock();
            Block ruleBlock = checkRules(nextBlock);

            if(ruleBlock == Block::NONE) {
                map_.moveTile(tile, dir);
            } else {
                switch (ruleBlock) {
                    case Block::STOP: {
                        break;
                    }
                    case Block::PUSH: {
                        move(nextTile, dir);
                        if(nextTile.getPosition() != tile.getPosition().next(dir)) {
                            map_.moveTile(tile, dir);
                        }
                        break;
                    }
                    case Block::WIN: {
                        map_.moveTile(tile, dir);
                        break;
                    }
                    case Block::SINK: {
                        if (tile == *playerBlocks_.at(0)) {
                            isLost_ = true;
                            endLevel();
                        } else {
                            map_.moveTile(tile, dir);
                            map_.removeTile(nextTile);
                            map_.removeTile(tile);
                        }
                        break;
                        }
                    case Block::SLIP: {
                        tile.move(dir);
                        move(tile, dir);
                        break;
                    }
                    case Block::MOVE: {
                        break;
                     }
                    case Block::KILL: {
                        isLost_ = true;
                        endLevel();
                        break;
                    }
                    case Block::YOU: {
                        map_.moveTile(tile, dir);
                        break;
                    }
                    default: {
                        map_.moveTile(tile, dir);
                    }
                }
            }
        }
    }
}

void Game::transformBlock() {
    for (auto & rule : listRules_) {
        BlockType textRule = rule.second.getBlockType();
        Block text = rule.first.getBlock();

        if (textRule == BlockType::TEXT && text != Block::NONE) {
            map_.transformTile(rule.first, rule.second);
        }
    }
}

bool Game::isGameWon(Position position) {
    Block block = searchListRules(Block::WIN);
    Block tile = static_cast<Block>(static_cast<int>(block) - 9);

    if (block != Block::NONE) {
        return map_.isGameWon(position, tile);
    }
    return false;
}

Block Game::searchListRules(Block block) {
    for (auto it = listRules_.begin(); it != listRules_.end(); ++it) {
        if (it->second.getBlock() == block) {
            return it->first.getBlock();
        }
    }
    return Block::NONE;
}


Block Game::checkRules(Block & block) {
    std::string str = to_string(block);
    str = "TEXT_" + str;

    for (const auto & rule : listRules_) {
        Block ruleBlock = rule.first.getBlock();

        if(to_string(ruleBlock) == str) {
            BlockType isRule = rule.second.getBlockType();

            if(BlockType::RULE == isRule) {
                return rule.second.getBlock();
            }
        }
    }
    return Block::NONE;
}

void Game::movePlayer(Direction dir) {
    bool isWon = false;
    initializeRules();
    findPlayer();
    std::cout << "MOVE PLAYER n playerblocks - " << playerBlocks_.size() << std::endl;

    for(unsigned long long i = 0; i < playerBlocks_.size() && !isWon; i++) {
        move(*playerBlocks_.at(i), dir);
        isWon = isGameWon(playerBlocks_.at(i)->getPosition());

        if (isWon) {
            wonLevel_ = true;
            endLevel();
        }
    }

    std::cout << "before notify" << std::endl;
    notifyObservers();

    std::cout << map_.to_string() << std::endl;
}

void Game::start() {
    notifyObservers();
}

void Game::nextLevel(int level) {
    map_.loadLevel(level);
}
void Game::saveGame(int level) {
    map_.saveMap(level);
}

void Game::loadLevel(int level) {
    map_.loadLevel(level);
    notifyObservers();
}

void Game::loadSavedLevel(int num){
    map_.loadSave(num);
    notifyObservers();
}

void Game::endLevel() {
    if(wonLevel_) {
        if(currentLevel_ < 4) {
            currentLevel_ ++;
            wonLevel_ = false;
            isLost_ = false;
            nextLevel(currentLevel_);
        }
    } else {
        loadLevel(currentLevel_);
    }
}

std::string Game::getMapRepresentation() {
    return map_.to_string();
}

void Game::addObserver(util::Observer* observer) {
    observers_.insert(observer);
}
void Game::notifyObservers() {
    std::cout <<" n obs: " << observers_.size() << std::endl;
    for (auto observer : observers_) {
        std::cout << "notified! " << observer << std::endl;
        observer->update();
    }
}

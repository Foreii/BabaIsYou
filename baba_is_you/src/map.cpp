#include "map.h"

using namespace model;

Map::Map(int level): observers_{std::set<util::Observer*>()} {
    loadLevel(level);
}

int Map::getHeight() const {
    return height_;
}

int Map::getWidth() const {
    return width_;
}

int Map::getLevel() const {
    return level_;
}

std::multimap<Position, Tile> Map::getMap() const {
    return map_;
}

void Map::moveTile(Tile & tile, Direction dir) {
    Position temp = tile.getPosition();

    auto range = map_.equal_range(temp);

    for (auto it = range.first; it != range.second; ++it) {
        if (it->second == tile) {
            map_.erase(it);
            break;
        }
    }
    tile.move(dir);

    map_.insert({tile.getPosition(), tile});

}

void Map::removeTile(Tile& tile) {
    Position temp = tile.getPosition();

    auto range = map_.equal_range(temp);

    for (auto it = range.first; it != range.second; ++it) {
        if (it->second == tile) {
            map_.erase(it);
            break;
        }
    }
}

Tile Map::getTile(Position position) const {
    Tile tile = {position, Block::BACKGROUND, BlockType::BLOCK};

    auto range = map_.equal_range(position);

    if (std::distance(range.first, range.second) == 0) {
        return tile;
    } else if (std::distance(range.first, range.second) == 1) {
        return range.first->second;
    }

    for (auto it = range.first; it != range.second; ++it) {
        if (it->second.getBlock() == Block::BABA) {
            return it->second;
        } else if (it->second.getBlock() == Block::ROCK) {
            tile = it->second;
        } else if (tile.getBlock() != Block::ROCK && (it->second.getBlockType() == BlockType::RULE || it->second.getBlockType() == BlockType::TEXT)) {
            tile = it->second;
        } else if (tile.getBlockType() != BlockType::RULE && tile.getBlockType() != BlockType::TEXT) {
            tile = it->second;
        }
    }
    return tile;
}

void Map::initializeRules(std::map<Tile, Tile> & map) {
    map.clear();
    for (auto it = map_.begin(); it != map_.end(); ++it) {
        BlockType blockType = it->second.getBlockType();

        if (blockType == BlockType::TEXT) {
            Position position = it->second.getPosition();
            bool verify = false;

            Tile rightTile = getTileAtDirection(position, Direction::RIGHT);
            Tile downTile = getTileAtDirection(position, Direction::DOWN);

            Tile rightRightTile = getTileAtDirection(rightTile.getPosition(), Direction::RIGHT);
            Tile downDownTile = getTileAtDirection(downTile.getPosition(), Direction::DOWN);

            if (rightTile.getBlock() == Block::IS) {
                verify = true;
                map.insert({it->second, rightRightTile});
            }
            if (downTile.getBlock() == Block::IS) {
                verify = true;
                map.insert({it->second, downDownTile});
            }

            if (verify) {
                map.insert({it->second, Tile()});
            }
        }
    }
}

std::vector<Tile *> Map::findBlock(const Tile & other) {
    std::vector<Tile *> arr;
    Block t = static_cast<Block>(static_cast<int>(other.getBlock()) - 9);

    for (auto& m : map_) {
        if (m.second.getBlock() == t) {
            arr.push_back(&m.second);
        }
    }

    return arr;
}

void Map::transformTile(Tile block, Tile blockTwo) {
    std::vector<Tile *> arr = findBlock(block);
    Block t1 = findBlock(blockTwo).at(0)->getBlock();

    for (unsigned long long i = 0; i < arr.size(); i++) {
        arr.at(i)->setBlock(t1);
    }

}

bool Map::isGameWon(Position position, Block block) {
    auto range = map_.equal_range(position);
    for (auto it = range.first; it != range.second; ++it) {
        if (it->second.getBlock() == block) {
            return true;
        }
    }
    return false;
}

std::string toLower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),[](unsigned char c){ return std::tolower(c); });
    return s;
}

Tile Map::getTileAtDirection(const Position& pos, Direction dir) const {
    Position nextPos = pos;
    nextPos = nextPos.next(dir);

    auto it = map_.find(nextPos);

    return it->second;
}


void Map::saveMap(int num) {
    std::string filename = "./resources/saves/save_" + std::to_string(num) + ".txt";
    std::ofstream save_file(filename);

    if (save_file.is_open()) {
        save_file << height_ << " " << width_ << "\n";
        for (auto const& [key, value] : map_) {
            save_file << toLower(value.to_string()) << " " << key << "\n";
        }
        save_file.close();
    } else {
        throw std::runtime_error("Failed to save game: save file not opened.");
    }
}

void Map::loadLevel(int level) {
    level_ = level;
    std::string path = "./resources/levels/level_" + std::to_string(level) + ".txt";
    std::ifstream file(path);

    if (!file) {
        throw std::runtime_error("Failed to load level file.");
    } else {
        convertFile(file);
    }
}

void Map::loadSave(int num) {
    level_ = num;
    std::string path = "./resources/saves/save_" + std::to_string(num) + ".txt";
    std::ifstream file(path);

    if (!file) {
        throw std::runtime_error("Failed to load save file.");

    } else {
        convertFile(file);
    }
}

bool Map::isInMap(Position pos) {
    return (pos.getX() >= 0 && pos.getY() >= 0)
            && (pos.getX() < width_ && pos.getY() < height_);
}

std::string Map::to_string() const {
    std::stringstream ss;

    ss << yellow << "WA_W" << reset << " ";
    for (int i = 0; i <= height_; i++) {
        //ss << "WA_W" << " ";
        ss << yellow << "WA_W" << reset << " ";
    }
    ss << "\n";

    for (int y = 0; y < height_; y++) {
        //ss << "WA_W" << " ";
        ss << yellow << "WA_W" << reset << " ";
        for (int x = 0; x < width_; x++) {
            Position pos{x, y};
            ss << to_print(getTile(pos).getBlock()) << " ";
        }
        //ss << "WA_W " << "\n";
        ss << yellow << "WA_W" << reset << " " << "\n";
    }

    //ss << "WA_W ";
    ss << yellow << "WA_W" << reset << " ";
    for (int i = 0; i <= height_; i++) {
        ss << yellow << "WA_W" << reset << " ";
        //ss << "WA_W ";
    }
    ss << "\n";

    return ss.str();
}

void Map::convertFile(std::ifstream& file) {
        map_.clear();
        std::string text;

        if(file.is_open()) {
            file >> width_ >> height_;
            std::string tileName;
            int x, y;

            while (file >> tileName >> x >> y) {
                auto it = block_map_.find(tileName);

                if (it == block_map_.end()) {
                    throw std::invalid_argument("Invalid block name.");
                }
                Position position(x, y);
                Block name = std::get<0>(it->second);
                BlockType type = std::get<1>(it->second);

                Tile tile(position, name, type);

                map_.insert({position, tile});
                file.ignore(10, '\n');
            }

            file.close();

        } else {
            throw std::invalid_argument("Could not open file.");
        }
        std::cout << to_string() << std::endl;
}

void Map::addObserver(util::Observer* observer) {
    observers_.insert(observer);
}
void Map::notifyObservers() {
    for (auto observer : observers_) {
        observer->update();
    }
}

bool model::operator<(const model::Position& firstPos, const model::Position& secondPos) {
    return (firstPos.getY() != secondPos.getY()) ? firstPos.getY() < secondPos.getY() : firstPos.getX() < secondPos.getX();
}


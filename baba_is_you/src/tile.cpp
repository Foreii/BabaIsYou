#include "tile.h"
#include "block.h"

using namespace model;

Tile::Tile() : position_(-1, -1) {}

Tile::Tile(Position position, Block block, BlockType type) : position_{position}, name_{block}, type_{type} {}

Tile::Tile(const Tile & tile):position_{tile.getPosition()} {
    name_ = tile.getBlock();
    type_ = tile.getBlockType();
}

void Tile::move(Direction dir) {
    position_.move(dir);
}

const Position& Tile::getPosition() const {
    return position_;
}

std::string Tile::to_string() const {
    return model::to_string(name_);
}

void Tile::setBlock(Block block) {
    name_ = block;
}

const Block & Tile::getBlock() const {
    return name_;
}

const BlockType & Tile::getBlockType() const {
    return type_;
}

std::ostream & model::operator<<(std::ostream & out, const Tile & in) {
    return out << in.to_string();
}

Tile & Tile::operator=(const Tile& other) {
    if (this == &other) {
        return *this;
    }

    position_ = other.position_;
    name_ = other.name_;
    type_ = other.type_;

    return *this;
}

bool model::operator<(const model::Tile& lhs, const model::Tile& rhs) {
    if (lhs.getPosition().getY() < rhs.getPosition().getY()) {
        return true;
    }
    else if (lhs.getPosition().getY() > rhs.getPosition().getY()) {
        return false;
    }
    else {
        return lhs.getPosition().getX() < rhs.getPosition().getX();
    }
}

bool model::operator==(const model::Tile& lhs, const model::Tile& rhs) {
    return (lhs.getBlockType() == rhs.getBlockType()
             && lhs.getBlock() == rhs.getBlock()
             && lhs.getPosition() == rhs.getPosition());
}


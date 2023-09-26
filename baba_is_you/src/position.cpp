#include "position.h"
#include <iostream>

using namespace model;

Position::Position(int x, int y): x_{x}, y_{y} { }

int Position::getX() const {
    return x_;
}

int Position::getY() const {
    return y_;
}

Position Position::next(Direction dir) const {
    int next_x;
    int next_y;
    Position pos{-1,-1};

    switch(dir) {
        case Direction::RIGHT: {
            next_x = x_ + 1;
            pos = Position(next_x, y_);
            break;
        }
        case Direction::UP: {
            next_y = y_ - 1;
            pos = Position(x_, next_y);
            break;
        }
        case Direction::LEFT: {
            next_x = x_ - 1;
            pos = Position(next_x, y_);
            break;
        }
        case Direction::DOWN:{
            next_y = y_ + 1;
            pos = Position(x_, next_y);
            break;
        }
    }
    return pos;
}

void Position::move(Direction dir) {
    switch(dir) {
        case Direction::RIGHT: {
            x_ += 1;
            break;
        }
        case Direction::UP: {
            y_ -= 1; // -1 because 0,0 position is on the top left corner
            break;
        }
        case Direction::LEFT: {
            x_ -= 1;
            break;
        }
        case Direction::DOWN: {
            y_ += 1;
            break;
        }
    }
}

void Position::setPosition(int x, int y) {
    x_ = x;
    y_ = y;
}

std::string Position::to_string() const {
    return std::to_string(this->getX()) + " " + std::to_string(this->getY());
}

bool Position::operator==(const Position& other) const {
    return (x_ == other.getX()) && (y_ == other.getY());
}

std::ostream & model::operator<<(std::ostream & out, const Position & in) {
    return out << in.to_string();
}

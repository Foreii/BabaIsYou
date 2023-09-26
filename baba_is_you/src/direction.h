#ifndef DIRECTION_H
#define DIRECTION_H

#include <ostream>

namespace model {
    enum class Direction {
        RIGHT,
        UP,
        LEFT,
        DOWN
    };

    /*!
     * \brief operator << returns the stream after the injection of the Direction.
     * \param os represents the output stream to which the Direction object will be written.
     * \param dir the direction that will be written.
     * \return the stream after the injection of the Direction.
     */
    inline std::ostream& operator<<(std::ostream& os, const Direction& dir) {
        switch (dir) {
            case Direction::RIGHT:
                os << "RIGHT";
                break;
            case Direction::UP:
                os << "UP";
                break;
            case Direction::LEFT:
                os << "LEFT";
                break;
            case Direction::DOWN:
                os << "DOWN";
                break;
        }
        return os;
    }
}

#endif // DIRECTION_H

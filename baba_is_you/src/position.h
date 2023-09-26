#ifndef POSITION_H
#define POSITION_H

#include "direction.h"
#include <ostream>

namespace model {
    class Position {
    private:
        int x_;
        int y_;

    public:
        /*!
         * \brief Position the constructor of Position.
         * \param x the x coordinate.
         * \param y the y coordinate.
         */
        Position(int x, int y);

        int getX() const;
        int getY() const;
        void setPosition(int x, int y);

        /*!
         * \brief move moves a position in a given direction.
         * \param dir the given direction.
         */
        void move(Direction dir);

        /*!
         * \brief next gives the next position for a given direction.
         * \param dir the given direction.
         * \return the next position for a given direction.
         */
        Position next(Direction dir) const;

        /*!
         * \brief to_string returns the string representation of the position.
         * \return the string representation for the position.
         */
        std::string to_string() const;

        /*!
         * \brief operator == returns whether two positions are equal or not.
         * \param other the second position.
         * \return whether two positions are equal or not.
         */
        bool operator==(const Position& other) const;

    };

    /*!
     * \brief operator << returns the stream after the injection of the Direction.
     * \param os represents the output stream to which the Direction object will be written.
     * \param direction the direction that will be written.
     * \return the stream after the injection of the Direction.
     */
    std::ostream & operator<<(std::ostream & os, const Position & in);

}

#endif // POSITION_H

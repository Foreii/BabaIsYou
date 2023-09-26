#ifndef TILE_H
#define TILE_H

#include "position.h"
#include "direction.h"
#include "block.h"
#include "blocktype.h"

namespace model {
    class Tile {
    private:
        Position position_;
        Block name_;
        BlockType type_;

    public:
        /*!
         * \brief Tile the first constructor of Tile, that is initialized at the position {-1; -1}.
         */
        Tile();

        /*!
         * \brief Tile the second constructor of Tile, that initializes the tile with given attributes.
         * \param position the given position.
         * \param block the given block.
         * \param type the given type of block.
         * \param isUnique whether the block is unique or there could be multiples instances in the game.
         */
        Tile(Position position, Block block, BlockType type);

        /*!
         * \brief Tile copy constructor.
         * \param tile the tile to copy.
         */
        Tile(const Tile & tile);

        const Position & getPosition() const;
        const Block & getBlock() const;
        const BlockType & getBlockType() const;

        void setBlock(Block block);

        /*!
         * \brief move moves the tile to a position given by the direction.
         * \param dir the direction that gives the position.
         */
        void move(Direction dir);

        /*!
         * \brief to_string returns the string representation of the tile.
         * \return the string representation of the tile.
         */
        std::string to_string() const;


        Tile & operator=(const Tile & other);

    };

    /*!
     * \brief operator << returns the stream after the injection of the Tile.
     * \param os represents the output stream to which the Tile object will be written.
     * \param in the tile that will be written.
     * \return the stream after the injection of the Tile.
     */
    std::ostream & operator<<(std::ostream & os, const Tile & in);

    /*!
     * \brief operator < returns whether the tileOne is "smaller"
     * (depending on the position) than the the tileTwo.
     * \param tileOne the first tile.
     * \param tileTwo the second tile.
     * \return whether the tileOne is "smaller" than the the tileTwo.
     */
    bool operator<(const model::Tile & tileOne, const model::Tile & tileTwo);

    /*!
     * \brief operator == returns whether two tiles are equal or not.
     * \param tileOne the first tile.
     * \param tileTwo the second tile.
     * \return whether two tiles are equal or not.
     */
    bool operator==(const model::Tile & tileOne, const model::Tile & tileTwo);

}
#endif // TILE_H

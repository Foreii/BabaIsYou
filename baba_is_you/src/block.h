#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <string>
#include <map>

namespace model {
    enum class Block {
        BABA,
        ROCK,
        WALL,
        FLAG,
        GRASS,
        LAVA,
        METAL,
        WATER,
        BONE,
        TEXT_BABA,
        TEXT_ROCK,
        TEXT_WALL,
        TEXT_FLAG,
        TEXT_GRASS,
        TEXT_LAVA,
        TEXT_METAL,
        TEXT_WATER,
        TEXT_BONE,
        IS,
        STOP,
        PUSH,
        YOU,
        WIN,
        SINK,
        SLIP,
        MOVE,
        KILL,
        NONE,
        BACKGROUND
    };

    /*!
     * \brief to_string returns a string representation of the block.
     * \param block the block to interpret.
     * \return a string representation of the block.
     */
    inline std::string to_string(Block block) {
        switch(block) {
            case Block::BABA :
                return "BABA";
            case Block::ROCK :
                return "ROCK";
            case Block::WALL :
                return "WALL";
            case Block::FLAG :
                return "FLAG";
            case Block::GRASS :
                return "GRASS";
            case Block::LAVA :
                return "LAVA";
            case Block::METAL :
                return "METAL";
            case Block::WATER :
                return "WATER";
            case Block::BONE :
                return "BONE";
            case Block::TEXT_BABA :
                return "TEXT_BABA";
            case Block::TEXT_ROCK :
                return "TEXT_ROCK";
            case Block::TEXT_WALL :
                return "TEXT_WALL";
            case Block::TEXT_FLAG :
                return "TEXT_FLAG";
            case Block::TEXT_GRASS :
                return "TEXT_GRASS";
            case Block::TEXT_LAVA :
                return "TEXT_LAVA";
            case Block::TEXT_METAL :
                return "TEXT_METAL";
            case Block::TEXT_WATER :
                return "TEXT_WATER";
            case Block::TEXT_BONE :
                return "TEXT_BONE";
            case Block::STOP :
                return "STOP";
            case Block::PUSH :
                return "PUSH";
            case Block::YOU :
                return "YOU";
            case Block::IS:
                return "IS";
            case Block::WIN :
                return "WIN";
            case Block::SINK :
                return "SINK";
            case Block::SLIP :
                return "SLIP";
            case Block::MOVE :
                return "MOVE";
            case Block::KILL :
                return "KILL";
            case Block::NONE:
                return "NONE";
            case Block::BACKGROUND:
                return "BACKGROUND";
            default: throw std::invalid_argument("This block doesn't exist!");
        }
    }

    /*!
     * \brief operator << returns the stream after the injection of the Block.
     * \param os represents the output stream to which the Block object will be written.
     * \param block the block that will be written.
     * \return the stream after the injection of the Block.
     */
    inline std::ostream& operator<<(std::ostream& os, Block block) {
        return os << to_string(block);
    }

    /*!
     * \brief to_print returns the colored representation of the block.
     * \param block the block to print in ascii colors.
     * \return the colored representation of the block.
     */
    inline std::string to_print(Block block) {
        std::string gray = "\033[0;37m";
        std::string black = "\033[30m";
        std::string red = "\033[31m";
        std::string green = "\033[32m";
        std::string yellow = "\033[33m";
        std::string blue = "\033[34m";
        std::string magenta = "\033[35m";
        std::string cyan = "\033[36m";
        std::string white = "\033[37m";
        std::string reset = "\033[0m";

        switch(block) {
            case Block::BABA :
                return yellow + "BA_B" + reset;
            case Block::ROCK :
                return red + "RO_B" + reset;
            case Block::WALL :
                return green + "WA_B" + reset;
            case Block::FLAG :
                return yellow + "FL_B" + reset;
            case Block::GRASS :
                return green + "GR_B" + reset;
            case Block::LAVA :
                return yellow + "LA_B" + reset;
            case Block::METAL :
                return magenta + "ME_B" + reset;
            case Block::WATER :
                return cyan + "WA_B" + reset;
            case Block::BONE :
                return yellow + "BO_B" + reset;
            case Block::TEXT_BABA :
                return green + "BA_T" + reset;
            case Block::TEXT_ROCK :
                return green + "RO_T" + reset;
            case Block::TEXT_WALL :
                return green + "WA_T" + reset;
            case Block::TEXT_FLAG :
                return green + "FL_T" + reset;
            case Block::TEXT_GRASS :
                return green + "GR_T" + reset;
            case Block::TEXT_LAVA :
                return green + "LA_T" + reset;
            case Block::TEXT_METAL :
                return green + "ME_T" + reset;
            case Block::TEXT_WATER :
                return green + "WA_T" + reset;
            case Block::TEXT_BONE :
                return green + "BO_T" + reset;
            case Block::IS:
                return red + "IS_R" + reset;
            case Block::STOP :
                return red + "ST_R" + reset;
            case Block::PUSH :
                return red + "PU_R" + reset;
            case Block::YOU :
                return red + "YO_R" + reset;
            case Block::WIN :
                return red + "WI_R" + reset;
            case Block::SINK :
                return red + "SI_R" + reset;
            case Block::SLIP :
                return red + "SL_R" + reset;
            case Block::MOVE :
                return red + "MO_R" + reset;
            case Block::KILL :
                return red + "KI_R" + reset;
            case Block::BACKGROUND:
                return black + "BA_B" + reset;
            default: {
                throw std::invalid_argument("This block doesn't exist!");
            }
        }
    }
}

#endif // BLOCK_H

#ifndef MAP_H
#define MAP_H

#include "observable.h"
#include "direction.h"
#include "position.h"
#include "tile.h"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <set>
#include <map>

namespace model {
    class Map: public util::Observable {

    private:
        int height_;
        int width_;
        int level_;

        std::multimap<Position, Tile> map_;

        std::set<util::Observer*> observers_;

        std::map<std::string, std::tuple<Block, BlockType, bool>> block_map_{
                {"baba", {Block::BABA, BlockType::BLOCK, true}},
                {"rock", {Block::ROCK, BlockType::BLOCK, true}},
                {"wall", {Block::WALL, BlockType::BLOCK, true}},
                {"flag", {Block::FLAG, BlockType::BLOCK, true}},
                {"grass", {Block::GRASS, BlockType::BLOCK, true}},
                {"lava", {Block::LAVA, BlockType::BLOCK, true}},
                {"metal", {Block::METAL, BlockType::BLOCK, true}},
                {"water", {Block::WATER, BlockType::BLOCK, true}},
                {"bone", {Block::BONE, BlockType::BLOCK, true}},
                {"text_baba", {Block::TEXT_BABA, BlockType::TEXT, true}},
                {"text_rock", {Block::TEXT_ROCK, BlockType::TEXT, true}},
                {"text_wall", {Block::TEXT_WALL, BlockType::TEXT, true}},
                {"text_flag", {Block::TEXT_FLAG, BlockType::TEXT, true}},
                {"text_grass", {Block::TEXT_GRASS, BlockType::TEXT, true}},
                {"text_lava", {Block::TEXT_LAVA, BlockType::TEXT, true}},
                {"text_metal", {Block::TEXT_METAL, BlockType::TEXT, true}},
                {"text_water", {Block::TEXT_WATER, BlockType::TEXT, true}},
                {"text_bone", {Block::TEXT_BONE, BlockType::TEXT, true}},
                {"stop", {Block::STOP, BlockType::RULE, true}},
                {"push", {Block::PUSH, BlockType::RULE, true}},
                {"you", {Block::YOU, BlockType::RULE, true}},
                {"is", {Block::IS, BlockType::RULE, true}},
                {"win", {Block::WIN, BlockType::RULE, true}},
                {"sink", {Block::SINK, BlockType::RULE, true}},
                {"slip", {Block::SLIP, BlockType::RULE, true}},
                {"move", {Block::MOVE, BlockType::RULE, true}},
                {"kill", {Block::KILL, BlockType::RULE, true}}
        };

        std::string yellow = "\033[33m";
        std::string reset = "\033[0m";

        /*!
         * \brief getTileAtDirection returns the tile that is in the direction of the given position.
         * \param pos the given position.
         * \param dir the given direction.
         * \return the tile that is in the direction of the given position.
         */
        Tile getTileAtDirection(const Position & pos, Direction dir) const;

        /*!
         * \brief convertFile converts the level's file by puting the content into the map.
         * \param file the level's file.
         */
        void convertFile(std::ifstream& file);

    public:
        /*!
         * \brief Map the constructor of Map, load the content of the first level.
         * \param level
         */
        Map(int level);

        /*!
         * \brief initializeRules initializes the rules in the listRules by iterating through the map.
         * \param map the listRules.
         */
        void initializeRules(std::map<Tile, Tile> & mapRules);

        int getHeight() const;
        int getWidth() const;
        int getLevel() const;
        std::multimap<Position, Tile> getMap() const;

        /*!
         * \brief moveTilemoves moves the tile to a position.
         * \param tile the given tile.
         * \param dir the given direction that will give the position.
         */
        void moveTile(Tile & tile, Direction dir);

        /*!
         * \brief saveMap saves the map of the given level
         * \param num the number of the level to save.
         */
        void saveMap(int level);

        /*!
         * \brief loadSave loads the map of the given level's save.
         * \param level the number of the given level's save.
         */
        void loadSave(int level);

        /*!
         * \brief loadLevel loads the map of the given level.
         * \param level the number of the given livel.
         */
        void loadLevel(int level);

        /*!
         * \brief isInMap verifies if a given position is within the bound of the map.
         * \param pos the given position.
         * \return the given position within the bound of the map.
         */
        bool isInMap(Position pos);

        /*!
         * \brief transformTile transforms the block in the tile to the second one.
         * \param block the first block.
         * \param blockTwo the second block.
         */
        void transformTile(Tile blockFirst, Tile blockTwo);

        /*!
         * \brief isGameWon verifies if the block is at the given positio, if it is the case the game is won.
         * \param position the position.
         * \param block the block.
         * \return if the block is at the given position.
         */
        bool isGameWon(Position position, Block block);

        /*!
         * \brief findBlock finds the block for its text block counterpart.
         * \param other the text block.
         * \return the block for its text block counterpart.
         */
        std::vector<Tile *> findBlock(const Tile & other);

        /*!
         * \brief getTile gets the tile for a given position. Since there could be
         * multiple tiles for a position, the taken one is by order :
         * 1. A rock.
         * 2. A text_block, rule_block or is_block.
         * 3. Other blocks but the metal block.
         * 4. The metal block.
         * \param position
         * \return
         */
        Tile getTile(Position position) const;

        /*!
         * \brief removeTile removes the first occurence of the tile in the map.
         * \param tile the tile given.
         */
        void removeTile(Tile& tile);

        /*!
         * \brief to_string returns a string representation of the map.
         * \return a string representation of the map.
         */
        std::string to_string() const;

        /*!
         * \brief addObserver adds an observer to the list of observers.
         * \param observer the observer.
         */
        void addObserver(util::Observer * observer);

        /*!
         * \brief notifyObservers notifies with the update method all
         *  the observers that are in the list of observers.
         */
        void notifyObservers();

    };

    /*!
     * \brief operator < returns whether posOne is bigger or smaller.
     * \param posOne the first position.
     * \param posTwo the second position.
     * \return whether posOne is bigger or smaller.
     */
    bool operator<(const model::Position& posOne, const model::Position& posTwo);

}

#endif // MAP_H

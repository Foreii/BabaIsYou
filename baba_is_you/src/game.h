#ifndef GAME_H
#define GAME_H

#include "direction.h"
#include "observer.h"
#include "tile.h"
#include "map.h"

#include <iostream>
#include <utility>
#include <vector>
#include <map>

namespace model {
    class Game: public util::Observable{

    private:
        int currentLevel_;
        int lastLevel_ = 4;
        bool wonLevel_ = false;
        bool isLost_ = false;

        Map map_;

        std::map<Tile, Tile> listRules_;
        std::set<util::Observer*> observers_;

        std::vector<Tile*> playerBlocks_;

        /*!
         * \brief move moves the tile to a position if it is in the map.
         * \param tile the tile to move.
         * \param dir the direction where the tile is moving to.
         */
        void move(Tile & tile, Direction dir);

        /*!
         * \brief findPlayer finds in the listRules what Block is
         * associated with the block "YOU" which defines the player.
         */
        void findPlayer();

        /*!
         * \brief endLevel if there is still levels left,
         * go onto the next one, if not stops the game.
         */
        void endLevel();

        /*!
         * \brief initializeRules initializes all the rules present by iterating on the map.
         */
        void initializeRules();

        /*!
         * \brief checkRules retrieves the active rule for the block.
         * \param block The block.
         * \return The active rule for the block.
         */
        Block checkRules(Block & block);

        /*!
         * \brief transformBlock transforms a text block into a different text block, for every TEXT is TEXT rule.
         */
        void transformBlock();

        /*!
         * \brief isGameWon verifies the win condition rule and returns if the player has won.
         * \param position the position of the actual player.
         * \return if the player has won.
         */
        bool isGameWon(Position position);

        /*!
         * \brief searchListRules searches if a rule block is in the list rules and returns its associated text block.
         * \param block the rule block.
         * \return the associated text block of a rule block.
         */
        Block searchListRules(Block block);

    public:
        /*!
         * \brief Game the Constructor of Game.
         * \param level the level the map will be initialized with.
         */
        Game(int level = 0);

        /*!
         * \brief start starts the game.
         */
        void start();

        /*!
         * \brief movePlayer moves the player to a position if it is in the map.
         * \param dir the direction where the player is moving to.
         */
        void movePlayer(Direction dir);

        /*!
         * \brief getGameState returns whether the player won or not.
         * \return true if the player has won, false otherwise.
         */
        bool getGameState();

        /*!
         * \brief getMapRepresentation returns the map's string representation.
         * \return the map's string representation.
         */
        std::string getMapRepresentation();

        /*!
         * \brief getLevel returns the current level.
         * \return the current level.
         */
        int getLevel();

        /*!
         * \brief getMapWidth returns the map's width.
         * \return the map's width.
         */
        int getMapWidth();

        const model::Map& getMap() const;

        /*!
         * \brief isGameLost checks if the game is lost.
         * \return true if game is lost, false otherwise.
         */
        bool isGameLost();

        /*!
         * \brief saveGame saves the game.
         * \param level the current level.
         */
        void saveGame(int level);

        /*!
         * \brief loadLevel loads the level.
         * \param level the number of the level.
         */
        void loadLevel(int level);

        /*!
         * \brief loadSavedLevel loads the saved level.
         * \param level the number of the saved level.
         */
        void loadSavedLevel(int level);

        /*!
         * \brief nextLevel loads the next level.
         */
        void nextLevel(int level);

        /*!
         * \brief addObserver adds an observer to the list of observers.
         * \param observer the observer.
         */
        void addObserver(util::Observer* observer);

        /*!
         * \brief notifyObservers notifies with the update method all
         *  the observers that are in the list of observers.
         */
        void notifyObservers();

    };
}

#endif // GAME_H

#ifndef FACADE_H
#define FACADE_H

#include "direction.h"
#include "observer.h"
#include "game.h"

namespace model {
    class Facade {
    public:
        Game game_;

        /*!
         * \brief Facade the constructor of Facade.
         * \param level the level the map will be initialized with.
         */
        Facade(int level);

        /*!
         * \brief start starts the game.
         */
        void start();

        /*!
         * \brief movePlayer moves the player to a position if it is in the map.
         * \param dir the direction where the player is moving to.
         */
        void movePlayer(std::string dir);

        /*!
         * \brief getGameState returns whether the player won or not.
         * \return whether the player won or not.
         */
        bool getGameState();

        /*!
         * \brief geMap returns the map.
         * \return the map;.
         */
        std::multimap<Position, Tile> getMap();

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

        /*!
         * \brief saveGame saves the game.
         * \param level the current level.
         */
        void saveGame();

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
        void nextLevel();

        /*!
         * \brief addObserver adds an observer to the list of observers.
         * \param observer the observer.
         */
        void addObserver(util::Observer* observer);

    };
}

#endif // FACADE_H

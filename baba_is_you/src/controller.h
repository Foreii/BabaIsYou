#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "view.h"
#include "facade.h"

#include <iostream>

namespace controller {
    class Controller {
    public:
        int argc_;
        char ** argv_;
        std::string mode_;
        model::Facade game_;
        view::View* view_;

        /*!
         * \brief Controller the constructor of the game's controller
         * \param argc argument count recieved from main class
         * \param argv pointers argument recieved from main class
         * \param mode the display mode for the game (console or gui)
         */
        Controller(int argc, char** argv, std::string mode);

        void setView(view::View* view);

        /*!
         * \brief start starts the game.
         */
        int start();

        /*!
         * \brief runGUI runs the graphical interface of the game.
         * \param argc argument count recieved from main class
         * \param argv pointers argument recieved from main class
         * \return the exit status of the application
         */
        int runGUI(int& argc, char ** argv);

        /*!
         * \brief runConsole runs the console version of the game.
         * \return the exit status of the application
         */
        int runConsole();

        /*!
         * \brief treatInput treats user's input.
         * \return boolean to stop treating inputs in some cases.
         */
        bool treatInput(std::string in);

    };
}

#endif // CONTROLLER_H

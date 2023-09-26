#ifndef CONSOLE_H
#define CONSOLE_H

#include "view.h"
//#include "direction.h"
#include "facade.h"



namespace controller { class Controller; }

namespace view {
    class Console: public View {
    public:
        model::Facade & game_;
        controller::Controller* controller_;

        /*!
         * \brief Console constructor of Console
         * \param game the game given by the Controller.
         * \param controller a pointer to the controller.
         */
        Console(model::Facade & game, controller::Controller* controller);

        /*!
         * \brief showLevel shows the current level of the game.
         */
        void showLevel();

        /*!
         * \brief showMessage shows the given message.
         * \param msg the given message.
         */
        void showMessage(std::string msg);

        /*!
         * \brief showHeader shows a header.
         */
        void showHeader();

        /*!
         * \brief update called whenever the observed object is changed.
         */
        void update();

        /*!
         * \brief showHelp shows help for the user's commands.
         */
        void showHelp();


        /*!
         * \brief treatInput treats user's input.
         */
        void treatInput();

//    private:
//        /*!
//         * \brief treatCommand executes the command depending on the user's input.
//         * \return a string of the user's input.
//         */
//        std::string treatCommand();

    };
}

#endif // CONSOLE_H

#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include "observer.h"
//#include "direction.h"

namespace view {
    class View: public util::Observer {
    public:
        /*!
         * \brief showHelp shows help for the user's commands.
         */
        virtual void showHelp() = 0;

        virtual void showLevel() = 0;

        /*!
         * \brief showHeader shows a header.
         */
        virtual void showHeader() = 0;

        /*!
         * \brief showMessage shows the given message.
         * \param msg the given message.
         */
        virtual void showMessage(std::string msg) = 0;

        /*!
         * \brief treatInput treats user's input.
         */
        virtual void treatInput() = 0;

        /*!
         * \brief update called whenever the observed object is changed.
         */
        virtual void update() = 0;
    };
}
#endif // VIEW_H

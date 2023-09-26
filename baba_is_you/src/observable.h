#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "observer.h"
namespace util {
    class Observable {
    public:

        /*!
         * \brief addObserver adds an observer to the list of observers.
         * \param observer the observer.
         */
        virtual void addObserver(Observer* observer) = 0;

        /*!
         * \brief notifyObservers notifies with the update method all
         *  the observers that are in the list of observers.
         */
        virtual void notifyObservers() = 0;
    };
}

#endif // OBSERVABLE_H

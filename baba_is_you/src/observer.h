#ifndef OBSERVER_H
#define OBSERVER_H

namespace util {
    class Observer {
    public:
        /*!
         * \brief update called whenever the observed object is changed.
         */
        virtual void update() = 0;
    };
}

#endif // OBSERVER_H

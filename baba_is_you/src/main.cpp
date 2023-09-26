#include "controller.h"

int main(int argc, char *argv[])
{
    std::string mode{"gui"};
    controller::Controller controller {argc, argv, mode};

    return controller.start();
}

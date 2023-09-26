#include <QApplication>
#include "console.h"
#include "controller.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "view.h"
#include <regex>


using namespace controller;

Controller::Controller(int argc, char** argv, std::string mode): argc_{argc}, argv_{argv}, mode_{mode}, game_{model::Facade(0)}, view_{nullptr}{

}

int Controller::start() {
    int exitStatus;

    if (this->mode_ == "console") {
        exitStatus = this->runConsole();

    } else if (this->mode_ == "gui"){
        exitStatus = this->runGUI(argc_, argv_);

    } else {
        throw std::invalid_argument("No playing mode was chosen on game startup");
    }

    return exitStatus;

}

void Controller::setView(view::View* view) {
    this->view_ = view;
}

int Controller::runGUI(int& argc, char** argv) {
    QApplication application(argc, argv);
    MainWindow gui{game_, this};

    this->setView(&gui);

//    view_.setGame(game_);
//    view_.setController(this);
//    MainWindow myWindow(game_, this);

//    this->view_(myWindow);

   dynamic_cast<MainWindow*>(view_)->show(); // cast back to real type for 1 use

    game_.start();

    return application.exec();
}

int Controller::runConsole() {

    view::Console console{game_, this};
    this->setView(&console);

    game_.start();

//    while (true) {

    try {
        view_->treatInput();

    } catch (std::exception& e) {

        view_->showMessage("ERROR | " + std::string(e.what()));

    }
    return 0;
}

bool Controller::treatInput(std::string in) {
    bool stop = false;
    std::regex pattern("load save (\\d+)");
    std::smatch match;

    if (in == "help") {

        this->view_->showHelp();

    } else if (in == "restart") {

        stop = true;
        game_.loadLevel(game_.getLevel());

    } else if (in == "save") {

        stop = true;
        game_.saveGame();

    } else if (std::regex_search ( in, match, pattern )) {

        stop = true;
        game_.loadSavedLevel(stoi(match[1]));

    } else if (in == "quit") {

       exit(0);

    } else if (in == "z"
               || in == "q"
               || in == "s"
               || in == "d") {

        game_.movePlayer(in);

    } else {
        this->view_->showHelp();
    }

    if(mode_ == "console") {
        this->view_->treatInput();
    }

    return stop;
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/qgraphicsscene.h>
#include <QKeyEvent>
#include "controller.h"
#include "view.h"

namespace Ui {
class MainWindow;
}

//namespace controller { class Controller; }


class MainWindow : public QMainWindow, public view::View
{
    Q_OBJECT

private:
    model::Facade & game_;
    controller::Controller* controller_;
    std::string dir = "d";
    Ui::MainWindow *ui;
    QGraphicsScene _scene ;

public:
    explicit MainWindow(model::Facade & game, controller::Controller* controller, QWidget *parent= nullptr);

    ~MainWindow();

    void setController_(controller::Controller* controller);

    void setGame_(model::Facade& game);

    /*!
     * \brief showLevel shows the current level of the game.
     */
    void showLevel() override;

    /*!
     * \brief showMessage shows the given message.
     * \param msg the given message.
     */
    void showMessage(std::string msg) override;

    /*!
     * \brief showHeader shows a header.
     */
    void showHeader() override;

    /*!
     * \brief update called whenever the observed object is changed.
     */
    void update() override;

    /*!
     * \brief showHelp shows help for the user's commands.
     */
    void showHelp() override;

    /*!
     * \brief treatInput returns the direction wanted by the user.
     * \param direction the direction for the player.
     * \return the direction that is wanted by the user.
     */
    void treatInput() override;


protected:
    void keyPressEvent(QKeyEvent *event) override;
};


#endif // MAINWINDOW_H

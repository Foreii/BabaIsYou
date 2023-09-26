#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "facade.h"
//#include "position.h"
//#include "direction.h"
//#include "tile.h"
//#include "block.h"
#include "tileDisplay.h"
#include <conio.h>
#include "controller.h"

#include <QGraphicsPixmapItem>
#include <QShortcut>
#include <QKeyEvent>


MainWindow::MainWindow(model::Facade & game, controller::Controller* controller, QWidget *parent)
    : QMainWindow(parent),
      game_{game},
      controller_{controller},
      ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    this->ui->myGraphicsView->setFocusPolicy(Qt::NoFocus);
    resize(40 * 19, 40 * 19);
    std::cout << "view ref" << this << std::endl;
    game_.addObserver(this);
    // this->showLevel();

    ui->myGraphicsView->setFixedSize(40 * 19, 40 * 19);
    ui->myGraphicsView->setScene(&_scene);
}


void MainWindow:: showLevel() {
    std::multimap<model::Position, model::Tile> map =  game_.getMap();
    TileDisplay t {&_scene};

    for (int i = 0; i <  game_.getMapWidth(); ++i) {
        for (int j = 0; j <  game_.getMapWidth(); ++j) {
            const model::Position position(i, j);

            auto tileRange = map.equal_range(position);

            if (std::distance(tileRange.first, tileRange.second) == 0) {
                t.drawBackground(i, j);
            }

            for (auto it = tileRange.first; it != tileRange.second; ++it) {
                const model::Tile& tile = it->second;

                if (tile.getBlock() == model::Block::BABA) {
                    if (dir == "z") {
                        t.drawBabaUp(i, j);
                    } else if (dir == "s") {
                        t.drawBabaDown(i, j);
                    } else if (dir == "q") {
                        t.drawBabaLeft(i, j);
                    } else {
                        t.drawBaba(i, j);
                    }
                } else if (tile.getBlock() == model::Block::TEXT_BABA) {
                    t.drawBabaText(i, j);
                }  else if (tile.getBlock() == model::Block::TEXT_BONE) {
                    t.drawBoneText(i, j);
                } else if (tile.getBlock() == model::Block::BONE) {
                    t.drawBone(i, j);
                } else if (tile.getBlock() == model::Block::WALL) {
                    t.drawWall(i, j);
                } else if (tile.getBlock() == model::Block::TEXT_WALL) {
                    t.drawWallText(i, j);
                } else if (tile.getBlock() == model::Block::FLAG) {
                    t.drawFlag(i, j);
                } else if (tile.getBlock() == model::Block::TEXT_FLAG) {
                    t.drawFlagText(i, j);
                } else if (tile.getBlock() == model::Block::TEXT_GRASS) {
                    t.drawGrassText(i, j);
                } else if (tile.getBlock() == model::Block::GRASS) {
                    t.drawGrass(i, j);
                } else if (tile.getBlock() == model::Block::IS) {
                    t.drawIs(i, j);
                } else if (tile.getBlock() == model::Block::KILL) {
                    t.drawKill(i, j);
                } else if (tile.getBlock() == model::Block::LAVA) {
                    t.drawLava(i, j);
                } else if (tile.getBlock() == model::Block::METAL) {
                    t.drawMetal(i, j);
                } else if (tile.getBlock() == model::Block::PUSH) {
                    t.drawPush(i, j);
                } else if (tile.getBlock() == model::Block::STOP) {
                    t.drawStop(i, j);
                } else if (tile.getBlock() == model::Block::ROCK) {
                    t.drawRock(i, j);
                } else if (tile.getBlock() == model::Block::TEXT_ROCK) {
                    t.drawRockText(i, j);
                } else if (tile.getBlock() == model::Block::WIN) {
                    t.drawWin(i, j);
                } else if (tile.getBlock() == model::Block::YOU) {
                    t.drawYou(i, j);
                } else if (tile.getBlock() == model::Block::WATER) {
                    t.drawWater(i, j);
                } else if (tile.getBlock() == model::Block::TEXT_WATER) {
                    t.drawWaterText(i, j);
                } else if (tile.getBlock() == model::Block::SINK) {
                    t.drawSink(i, j);
                }
            }
        }
    }
}

void MainWindow::showMessage(std::string msg) {}

void MainWindow::showHeader() {}

void MainWindow::update() {
    this->showLevel();
}

void MainWindow::showHelp() {}

void MainWindow::treatInput() {
    //return model::Direction{};
}


void MainWindow::keyPressEvent(QKeyEvent *event) {

    switch (event->key()) {
    case Qt::Key_Up:
        std::cout << "z";
        dir = "z";
        break;

    case Qt::Key_Down:
        dir = "s";
        break;

    case Qt::Key_Left:
        std::cout << "z";
        dir = "q";
        break;

    case Qt::Key_Right:
        dir = "d";
        break;

    case Qt::Key_R:
        dir = "restart";
        break;

    case Qt::Key_C:
        dir = "save";
        break;

    case Qt::Key_Escape:
        dir = "quit";
        break;

    default:
        dir = "none";
    }


    if (dir != "none") {
        _scene.clear();
        this->controller_->treatInput(dir);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

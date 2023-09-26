#ifndef TILEDISPLAY_H
#define TILEDISPLAY_H

#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "ImageLoader.h"

class TileDisplay {
public:
    TileDisplay(QGraphicsScene* scene) : _scene(scene) {}

    void drawWall(int i, int j) {
        QGraphicsPixmapItem* item = createPixmapItem(ImageLoader::wall(), i, j);
        _scene->addItem(item);
    }

    void drawWallText(int i, int j) {
        QGraphicsPixmapItem* item = createPixmapItem(ImageLoader::wall_text(), i, j);
        _scene->addItem(item);
    }
    void drawRockText(int i, int j) {
        QGraphicsPixmapItem* item = createPixmapItem(ImageLoader::rock_text(), i, j);
        _scene->addItem(item);
    }

    void drawBaba(int i, int j) {
        QGraphicsPixmapItem* item = createPixmapItem(ImageLoader::baba(), i, j);
        _scene->addItem(item);
    }

    void drawBabaText(int i, int j) {
        QGraphicsPixmapItem* item = createPixmapItem(ImageLoader::baba_text(), i, j);
        _scene->addItem(item);
    }

    void drawBone(int i, int j) {
        QGraphicsPixmapItem* item = createPixmapItem(ImageLoader::bone(), i, j);
        _scene->addItem(item);
    }

    void drawBoneText(int i, int j) {
        QGraphicsPixmapItem* item = createPixmapItem(ImageLoader::bone(), i, j);
        _scene->addItem(item);
    }

    void drawFlag(int i, int j) {
        QGraphicsPixmapItem* item = createPixmapItem(ImageLoader::flag(), i, j);
        _scene->addItem(item);
    }

    void drawFlagText(int i, int j) {
        QGraphicsPixmapItem* item = createPixmapItem(ImageLoader::flag_text(), i, j);
        _scene->addItem(item);
    }

    void drawIs(int i, int j) {
        QGraphicsPixmapItem* item = createPixmapItem(ImageLoader::is(), i, j);
        _scene->addItem(item);
    }

    void drawKill(int i, int j) {
        QGraphicsPixmapItem* item = createPixmapItem(ImageLoader::kill(), i, j);
        _scene->addItem(item);
    }

    void drawLava(int i, int j) {
        QGraphicsPixmapItem* item = createPixmapItem(ImageLoader::lava(), i, j);
        _scene->addItem(item);
    }

    void drawMove(int i, int j) {
        QGraphicsPixmapItem* item = createPixmapItem(ImageLoader::move(), i, j);
        _scene->addItem(item);
    }

    void drawPull(int i, int j) {
        QGraphicsPixmapItem* item = createPixmapItem(ImageLoader::pull(), i, j);
        _scene->addItem(item);
    }

    void drawPush(int i, int j) {
        QGraphicsPixmapItem* item = createPixmapItem(ImageLoader::push(), i, j);
        _scene->addItem(item);
    }

    void drawRock(int i, int j) {
        QGraphicsPixmapItem* item = createPixmapItem(ImageLoader::rock(), i, j);
        _scene->addItem(item);
    }

    void drawWin(int i, int j) {
        QGraphicsPixmapItem* item = createPixmapItem(ImageLoader::win(), i, j);
        _scene->addItem(item);
    }

    void drawMetal(int i, int j) {
        QGraphicsPixmapItem* item = createPixmapItem(ImageLoader::metal(), i, j);
        _scene->addItem(item);
    }

    void drawMetalText(int i, int j) {
        QGraphicsPixmapItem* item = createPixmapItem(ImageLoader::metal_text(), i, j);
        _scene->addItem(item);
    }

    void drawGrass(int i, int j) {
        QGraphicsPixmapItem* item = createPixmapItem(ImageLoader::grass(), i, j);
        _scene->addItem(item);
    }

    void drawGrassText(int i, int j) {
        QGraphicsPixmapItem* item = createPixmapItem(ImageLoader::grass_text(), i, j);
        _scene->addItem(item);
    }

    void drawStop(int i, int j) {
        QGraphicsPixmapItem* item = createPixmapItem(ImageLoader::stop(), i, j);
        _scene->addItem(item);
    }

    void drawBackground(int i, int j) {
        QGraphicsPixmapItem* item = createPixmapItem(ImageLoader::background(), i, j);
        _scene->addItem(item);
    }

    void drawYou(int i, int j) {
        QGraphicsPixmapItem* item = createPixmapItem(ImageLoader::you(), i, j);
        _scene->addItem(item);
    }

    void drawBabaDown(int i, int j) {
        QGraphicsPixmapItem* item = createPixmapItem(ImageLoader::baba_down(), i, j);
        _scene->addItem(item);
    }

    void drawBabaUp(int i, int j) {
        QGraphicsPixmapItem* item = createPixmapItem(ImageLoader::baba_up(), i, j);
        _scene->addItem(item);
    }


    void drawBabaLeft(int i, int j) {
        QGraphicsPixmapItem* item = createPixmapItem(ImageLoader::baba_left(), i, j);
        _scene->addItem(item);
    }

    void drawWaterText(int i, int j) {
        QGraphicsPixmapItem* item = createPixmapItem(ImageLoader::water_text(), i, j);
        _scene->addItem(item);
    }

    void drawWater(int i, int j) {
        QGraphicsPixmapItem* item = createPixmapItem(ImageLoader::water(), i, j);
        _scene->addItem(item);
    }

    void drawSink(int i, int j) {
        QGraphicsPixmapItem* item = createPixmapItem(ImageLoader::sink(), i, j);
        _scene->addItem(item);
    }

private:
    QGraphicsPixmapItem* createPixmapItem(const QPixmap& pixmap, int i, int j) {
        QGraphicsPixmapItem* item = new QGraphicsPixmapItem(pixmap);
        item->setPos(i * 40, j * 40);

        float scale = static_cast<float>(40) / pixmap.width();
        item->setScale(scale);

        return item;
    }

    QGraphicsScene* _scene;
};


#endif // TILEDISPLAY_H

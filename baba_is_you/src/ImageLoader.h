#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include "qpainter.h"
#include <QPixmap>

class ImageLoader {
public:
    static QPixmap extractSprite(const QPixmap& spriteSheet, int spriteWidth, int spriteHeight, int spriteX, int spriteY) {
        QPixmap sprite(spriteWidth - 1, spriteHeight - 1);
        sprite.fill(Qt::transparent);

        QPainter painter(&sprite);
        painter.drawPixmap(0, 0, spriteSheet, (spriteX * 25) + 1, (spriteY * 25) + 1, spriteWidth - 1, spriteHeight - 1);

        return sprite;
    }

    static QPixmap baba() {
        static QPixmap spriteSheet("./resources/sprites/object_characters_baba_is_you.png");
        QPixmap sprite = extractSprite(spriteSheet, 25, 25, 1, 0);
        return sprite;
    }

    static QPixmap baba_text() {
        static QPixmap spriteSheet("./resources/sprites/object_characters_baba_is_you.png");
        QPixmap sprite = extractSprite(spriteSheet, 25, 25, 22, 0);
        return sprite;
    }

    static QPixmap push() {
        static QPixmap spriteSheet("./resources/sprites/object_text_baba_is_you.png");
        QPixmap sprite = extractSprite(spriteSheet, 25, 25, 0, 14);
        return sprite;
    }

    static QPixmap pull() {
        static QPixmap spriteSheet("./resources/sprites/object_text_baba_is_you.png");
        QPixmap sprite = extractSprite(spriteSheet, 25, 25, 4, 14);
        return sprite;
    }

    static QPixmap is() {
        static QPixmap spriteSheet("./resources/sprites/object_text_baba_is_you.png");
        QPixmap sprite = extractSprite(spriteSheet, 25, 25, 9, 3);
        return sprite;
    }

    static QPixmap kill() {
        static QPixmap spriteSheet("./resources/sprites/kill.png");
        QPixmap sprite = extractSprite(spriteSheet, 25, 25, 0, 0);
        return sprite;
    }

    static QPixmap lava() {
        static QPixmap spriteSheet("./resources/sprites/lava.png");
        QPixmap sprite = extractSprite(spriteSheet, 25, 25, 0, 0);
        return sprite;
    }

    static QPixmap move() {
        static QPixmap spriteSheet("./resources/sprites/object_characters_baba_is_you.png");
        QPixmap sprite = extractSprite(spriteSheet, 25, 25, 0, 0);
        return sprite;
    }

    static QPixmap rock() {
        static QPixmap spriteSheet("./resources/sprites/object_static_baba_is_you.png");
        QPixmap sprite = extractSprite(spriteSheet, 25, 25, 9, 26);
        return sprite;
    }

    static QPixmap rock_text() {
        static QPixmap spriteSheet("./resources/sprites/object_static_baba_is_you.png");
        QPixmap sprite = extractSprite(spriteSheet, 25, 25, 8, 26);
        return sprite;
    }

    static QPixmap win() {
        static QPixmap image("./resources/sprites/win.png");
        return image;
    }

    static QPixmap flag() {
        static QPixmap spriteSheet("./resources/sprites/object_static_baba_is_you.png");
        QPixmap sprite = extractSprite(spriteSheet, 25, 25, 1, 9);
        return sprite;
    }

    static QPixmap baba_left() {
        static QPixmap spriteSheet("./resources/sprites/object_characters_baba_is_you.png");
        QPixmap sprite = extractSprite(spriteSheet, 25, 25, 9, 1);
        return sprite;
    }

    static QPixmap box() {
        static QPixmap spriteSheet("./resources/sprites/object_characters_baba_is_you.png");
        QPixmap sprite = extractSprite(spriteSheet, 25, 25, 0, 0);
        return sprite;
    }

    static QPixmap box_text() {
        static QPixmap spriteSheet("./resources/sprites/object_characters_baba_is_you.png");
        QPixmap sprite = extractSprite(spriteSheet, 25, 25, 0, 0);
        return sprite;
    }

    static QPixmap wall() {
        static QPixmap spriteSheet("./resources/sprites/tile_baba_is_you.png");
        QPixmap sprite = extractSprite(spriteSheet, 25, 25, 19, 61);
        return sprite;
    }

    static QPixmap bone() {
        static QPixmap spriteSheet("./resources/sprites/skull.png");
        QPixmap sprite = extractSprite(spriteSheet, 25, 25, 0, 0);
        return sprite;
    }

    static QPixmap metal() {
        static QPixmap spriteSheet("./resources/sprites/object_static_baba_is_you.png");
        QPixmap sprite = extractSprite(spriteSheet, 25, 25, 9, 30);
        return sprite;
    }

    static QPixmap metal_text() {
        static QPixmap image("./resources/sprites/metal_text.png");
        return image;
    }

    static QPixmap grass() {
        static QPixmap spriteSheet("./resources/sprites/tile_baba_is_you.png");
        QPixmap sprite = extractSprite(spriteSheet, 25, 25, 19, 29);
        return sprite;
    }

    static QPixmap grass_text() {
        static QPixmap spriteSheet("./resources/sprites/tile_baba_is_you.png");
        QPixmap sprite = extractSprite(spriteSheet, 25, 25, 18, 29);
        return sprite;
    }

    static QPixmap stop() {
        static QPixmap spriteSheet("./resources/sprites/object_text_baba_is_you.png");
        QPixmap sprite = extractSprite(spriteSheet, 25, 25, 7, 12);
        return sprite;
    }

    static QPixmap background() {
        static QPixmap image("./resources/sprites/green.png");
        return image;
    }

    static QPixmap wall_text() {
        static QPixmap spriteSheet("./resources/sprites/tile_baba_is_you.png");
        QPixmap sprite = extractSprite(spriteSheet, 25, 25, 18, 61);
        return sprite;
    }

    static QPixmap you() {
        static QPixmap spriteSheet("./resources/sprites/object_text_baba_is_you.png");
        QPixmap sprite = extractSprite(spriteSheet, 25, 25, 10, 9);
        return sprite;
    }

    static QPixmap baba_down() {
        static QPixmap spriteSheet("./resources/sprites/object_characters_baba_is_you.png");
        QPixmap sprite = extractSprite(spriteSheet, 25, 25, 13, 0);
        return sprite;
    }

    static QPixmap baba_up() {
        static QPixmap spriteSheet("./resources/sprites/object_characters_baba_is_you.png");
        QPixmap sprite = extractSprite(spriteSheet, 25, 25, 7, 0);
        return sprite;
    }

    static QPixmap flag_text() {
        static QPixmap spriteSheet("./resources/sprites/object_static_baba_is_you.png");
        QPixmap sprite = extractSprite(spriteSheet, 25, 25, 2, 10);
        return sprite;
    }

    static QPixmap sink() {
        static QPixmap image("./resources/sprites/sink.png");
        return image;
    }

    static QPixmap water() {
        static QPixmap spriteSheet("./resources/sprites/tile_baba_is_you.png");
        QPixmap sprite = extractSprite(spriteSheet, 25, 25, 19, 64);
        return sprite;
    }

    static QPixmap water_text() {
        static QPixmap spriteSheet("./resources/sprites/tile_baba_is_you.png");
        QPixmap sprite = extractSprite(spriteSheet, 25, 25, 18, 64);
        return sprite;
    }

private:
    ImageLoader() {}
};

#endif // IMAGELOADER_H

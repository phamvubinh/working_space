#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Bullet: public QObject,public QGraphicsPixmapItem      // to use the slot
{
    Q_OBJECT     // to use the slot
public:
    Bullet();
public slots:
    void move();
};

#endif // BULLET_H

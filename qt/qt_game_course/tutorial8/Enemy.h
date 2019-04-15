#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Enemy: public QObject,public QGraphicsPixmapItem     // to use the slot
{
    Q_OBJECT     // to use the slot
public:
    Enemy();
public slots:
    void move();
};

#endif // ENEMY_H

#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>

class Enemy: public QObject,public QGraphicsRectItem      // to use the slot
{
    Q_OBJECT     // to use the slot
public:
    Enemy();
public slots:
    void move();
};

#endif // ENEMY_H

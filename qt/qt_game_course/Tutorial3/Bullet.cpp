#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>

Bullet::Bullet()
{
    // drew the rect
    setRect(0,0,10,50);

    // connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    setPos(x(),y() - rect().height());
    if(pos().y() + rect().height() < 0)
    {
        scene()->removeItem(this);
        qDebug() << "bullet is deleted" << endl;
        delete this;
    }
}

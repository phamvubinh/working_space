#include "MyRect.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "Bullet.h"

void MyRect::keyPressEvent(QKeyEvent * event)
{
    if(event->key() == Qt::Key_Left)
    {
        setPos(x()-10, y());
    }
    else if(event->key() == Qt::Key_Right)
    {
        setPos(x()+10, y());
    }
    else if(event->key() == Qt::Key_Up)
    {
        setPos(x(), y()-10);
    }
    else if(event->key() == Qt::Key_Down)
    {
        setPos(x(), y()+10);
    }
    else if(event->key() == Qt::Key_Space)
    {
        Bullet * bullet = new Bullet();
        qDebug() << "bullet created" << endl;
        bullet->setPos(x(), y());
        scene()->addItem(bullet);
    }
    else
    {
        setPos(x(), y());
    }
}

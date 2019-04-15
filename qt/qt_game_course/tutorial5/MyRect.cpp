#include "MyRect.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "Bullet.h"
#include "Enemy.h"

void MyRect::keyPressEvent(QKeyEvent * event)
{
    if(event->key() == Qt::Key_Left)
    {
        if(pos().x()-10 >= 0)
        {
            setPos(x()-10, y());
        }
    }
    else if(event->key() == Qt::Key_Right)
    {
        if(pos().x() + rect().width() < 800)
        {
            setPos(x()+10, y());
        }
    }
    else if(event->key() == Qt::Key_Space)
    {
        Bullet * bullet = new Bullet();
        qDebug() << "bullet created" << endl;
        bullet->setPos(x() + rect().width()/2 - bullet->rect().width()/2, y());
        scene()->addItem(bullet);
    }
    else
    {
        setPos(x(), y());
    }
}

void MyRect::spawn()
{
    //create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

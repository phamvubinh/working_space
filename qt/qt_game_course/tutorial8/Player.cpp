#include "Player.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "Bullet.h"
#include "Enemy.h"


Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    // set graphic
    setPixmap(QPixmap(":/images/player.png"));
}

void Player::keyPressEvent(QKeyEvent * event)
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
        if(pos().x() + 10 < 800)
        {
            setPos(x()+10, y());
        }
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

void Player::spawn()
{
    //create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

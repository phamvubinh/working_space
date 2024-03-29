#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include "Enemy.h"
#include <typeinfo>
#include "Game.h"

extern Game * game;

Bullet::Bullet()
{
    // drew the rect
    // setRect(0,0,10,50);

    // draw graphics
    QImage image(":/images/bullet.png");
    image.scaled(2, 2);

    setPixmap(QPixmap(":/images/bullet.png"));

    // connect timeout event to move function
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    // if bullet collining with enemy, destroy both and increase the score
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if(typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            //increase the score
            game->score->increase();
            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    setPos(x(),y()-10);
    if(pos().y() < 0)
    {
        scene()->removeItem(this);
        qDebug() << "bullet is deleted" << endl;
        delete this;
    }
}

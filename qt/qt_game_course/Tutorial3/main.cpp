#include <QtGui/QApplication>
#include <QGraphicsScene>
#include "MyRect.h"
#include <QGraphicsView>
#include "Bullet.h"

/*
Tutorial Topics:
~event (keyPressEvent() and QKeyEvent()
~event propogation system
~QDebug
  */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scence
    QGraphicsScene * scene = new QGraphicsScene();

    // create an item to put into the scene
    MyRect * player = new MyRect();
    player->setRect(0, 0, 100, 100);

    // add the item to the scene
    scene->addItem(player);

    // make rect focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // add a view
    QGraphicsView * view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();

    view->setFixedSize(800, 600);
    scene->setSceneRect(0,0,800,600);

    // set the player to the center point of the view
    player->setPos(view->width()/2 - player->rect().width()/2, view->height() - player->rect().height());

    return a.exec();
}

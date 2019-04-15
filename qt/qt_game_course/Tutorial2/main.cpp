#include <QtGui/QApplication>
#include <QGraphicsScene>
#include "MyRect.h"
#include <QGraphicsView>

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
    MyRect * rect = new MyRect();
    rect->setRect(0, 0, 100, 100);

    // add the item to the scene
    scene->addItem(rect);

    // make rect focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    // add a view
    QGraphicsView * view = new QGraphicsView(scene);

    view->show();

    return a.exec();
}

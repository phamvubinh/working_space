#include <QtGui/QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

/*
  QGraphicsScene
  QGraphicsItem (QGraphicsRectItem)
  QGraphicsView
  */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scence
    QGraphicsScene * scene = new QGraphicsScene();

    // create an item to put into the scene
    QGraphicsRectItem * rect = new QGraphicsRectItem();
    rect->setRect(0, 0, 100, 100);

    // add the item to the scene
    scene->addItem(rect);

    // add a view
    QGraphicsView * view = new QGraphicsView(scene);

    view->show();

    return a.exec();
}

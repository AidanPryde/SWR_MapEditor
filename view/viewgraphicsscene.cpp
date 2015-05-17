#include "view\viewgraphicsscene.h"

#include <QGraphicsSceneMouseEvent>
#include <QTextStream>

#include <QDebug>

ViewGraphicsScene::ViewGraphicsScene(QObject *parent) :
    QGraphicsScene(parent)
{


    QPen blackPen(Qt::black);
    QBrush yellowBrush(Qt::yellow);
    QBrush redBrush(Qt::red);
    QBrush greenBrush(Qt::green);

    setBackgroundBrush(redBrush);

    setSceneRect(0, 0, 400, 400);

    for(int x = 0; x < 400; x = x + 25)
    {
        for(int y = 0; y < 400; y = y + 25)
        {
            if (x % 100 == 0 && y % 100 == 0) {
                addRect(x, y, 2, 2);

                QString pointString;
                QTextStream stream(&pointString);
                stream << "(" << x << "," << y << ")";
                QGraphicsTextItem* item =addText(pointString);
                item->setPos(x, y);
            } else {
                addRect(x, y, 1, 1);
            }
        }
    }

    ComponentList.push_back(new QPixmap("F:/Data_Torrent/SWR_MapEditor/s.jpg"));
    addPixmap(*ComponentList.first())->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);


}

ViewGraphicsScene::~ViewGraphicsScene()
{

}

/*void ViewGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    if (event->button() == Qt::RightButton)
    {
        QTransform noTransform;
        if (itemAt(event->scenePos().rx(), event->scenePos().ry(), noTransform) == nullptr)
        {
            qDebug() << "háttérre kattintás jobbal";
            AddNewSystem();
        }
        else
        {
            qDebug() << "elemre kattintás jobbal";
        }
    }
    else if (event->button() == Qt::LeftButton)
    {
        ItemClickedForDrag = true;
    }
}*/

void ViewGraphicsScene::AddNewComponent()
{
    //addPixmap(QPixmap &a("s.jpg"));
}

void ViewGraphicsScene::AddNewSystem()
{
    ComponentList.push_back(new QPixmap("F:/Data_Torrent/SWR_MapEditor/s.jpg"));
    addPixmap(*ComponentList.first())->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);

}

/*void ViewGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

}*/

/*void ViewGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
    {
        qDebug() << event->scenePos().rx();
        qDebug() << event->scenePos().ry();
        qDebug() << this->itemAt(event->scenePos().rx(), event->scenePos().ry(), QTransform());
    }
}*/

void ViewGraphicsScene::wheelEvent(QGraphicsSceneWheelEvent* wheelEvent)
{
    qDebug() << "ViewGraphicsScene::wheelEvent(QGraphicsSceneWheelEvent* wheelEvent)";
}

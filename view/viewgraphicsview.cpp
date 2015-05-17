#include "view\viewgraphicsview.h"

#include <QWheelEvent>

#include <QDebug>

ViewGraphicsView::ViewGraphicsView(QWidget *parent)
    : QGraphicsView(parent)
{
    QBrush yellowBrush(Qt::yellow);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setBackgroundBrush(yellowBrush);
}

ViewGraphicsView::~ViewGraphicsView()
{

}

void ViewGraphicsView::wheelEvent(QWheelEvent* event)
{
    qDebug() << "ViewGraphicsView::wheelEvent(QWheelEvent* event)";

    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

    double scaleFactorIn = 1.15;
    double scaleFactorOut = 1.0 / 1.15;
    if(event->delta() > 0)
    {
        scale(scaleFactorIn, scaleFactorIn);
    }
    else
    {
        scale(scaleFactorOut, scaleFactorOut);
    }
    //this->adjustSize();
}

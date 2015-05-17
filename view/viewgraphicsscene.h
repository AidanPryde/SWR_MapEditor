#ifndef VIEWGRAPHICSSCENE_H
#define VIEWGRAPHICSSCENE_H

#include "main/global.h"

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>

class QGraphicsSceneMouseEvent;
class QGraphicsItem;

class ViewGraphicsScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit ViewGraphicsScene(QObject *parent = 0);
    virtual ~ViewGraphicsScene();

protected slots:
    void wheelEvent(QGraphicsSceneWheelEvent * wheelEvent);
    //void mousePressEvent(QGraphicsSceneMouseEvent *event);
    /*void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);*/

private slots:
    void AddNewComponent();

private:    
    Q_DISABLE_COPY(ViewGraphicsScene)

    void AddNewSystem();

    QGraphicsItem* Base;
    QList<QPixmap *> ComponentList;
};

#endif // VIEWGRAPHICSSCENE_H

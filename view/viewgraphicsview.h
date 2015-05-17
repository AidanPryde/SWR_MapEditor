#ifndef VIEWGRAPHICSVIEW_H
#define VIEWGRAPHICSVIEW_H

#include <QGraphicsView>

class QWheelEvent;

class ViewGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit ViewGraphicsView(QWidget *parent = 0);
    virtual ~ViewGraphicsView();
protected slots:
    void wheelEvent(QWheelEvent * event);

private:
    Q_DISABLE_COPY(ViewGraphicsView)

};

#endif // VIEWGRAPHICSVIEW_H

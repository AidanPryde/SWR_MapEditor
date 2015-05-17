#ifndef VIEWOBJECT_H
#define VIEWOBJECT_H

#include <QGraphicsItem>

class ViewObject : public QGraphicsItem
{


public:
    explicit ViewObject(QGraphicsItem * parent = 0);
    virtual ~ViewObject();

private:
    Q_DISABLE_COPY(ViewObject)

};

#endif // VIEWOBJECT_H

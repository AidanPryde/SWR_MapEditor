#ifndef VIEWSYSTEM_H
#define VIEWSYSTEM_H

#include "view/viewobject.h"

class ViewSystem : public ViewObject
{


public:
    explicit ViewSystem(QGraphicsItem * parent = 0);
    virtual ~ViewSystem();

/*public slots:
    void SetPsition();*/

private:
    Q_DISABLE_COPY(ViewSystem)
};

#endif // VIEWSYSTEM_H

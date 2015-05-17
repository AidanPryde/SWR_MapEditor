#ifndef VIEWGALAXY_H
#define VIEWGALAXY_H

#include "view/viewobject.h"

class ViewGalaxy : ViewObject
{


public:
    explicit ViewGalaxy(QGraphicsItem * parent = 0);
    virtual ~ViewGalaxy();

private:
    Q_DISABLE_COPY(ViewGalaxy)
};

#endif // VIEWGALAXY_H

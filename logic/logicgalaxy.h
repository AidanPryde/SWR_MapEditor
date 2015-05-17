#ifndef LOGICGALAXY_H
#define LOGICGALAXY_H

#include "logic\logicobject.h"

#include <QVector>

class LogicGalaxy : public LogicObject
{
public:
    LogicGalaxy();
    ~LogicGalaxy();

private:
    QVector<LogicObject *> componentVector;
};

#endif // LOGICGALAXY_H

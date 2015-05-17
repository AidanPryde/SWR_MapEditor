#ifndef LOGICMAP_H
#define LOGICMAP_H

#include "logic\logicobject.h"
#include "logic\logicgalaxy.h"

class QFile;

class LogicMap : public QObject
{
public:
    LogicMap();
    LogicMap(QFile *file);
    ~LogicMap();

    void Init();
    void Load();
    void Save();

    LogicObject* base;
    QFile* mapFile;
};

#endif // LOGICMAP_H

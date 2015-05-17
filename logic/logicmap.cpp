#include "logic\logicmap.h"

#include <QFile>

LogicMap::LogicMap()
    : mapFile(nullptr)
{

}

LogicMap::LogicMap(QFile *file)
    : mapFile(file)
{

}

LogicMap::~LogicMap()
{
    if (mapFile != nullptr)
    {
        delete mapFile;
    }
}

void LogicMap::Init()
{
    base = new LogicGalaxy();
}


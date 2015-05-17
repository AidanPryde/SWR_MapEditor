#ifndef GLOBAL
#define GLOBAL

#include <QTypeInfo>
#include <QString>
#include <QDir>
#include <QSettings>

typedef __UINT_FAST8_TYPE__  INT08U;
typedef __UINT_FAST16_TYPE__ INT16U;
typedef __UINT_FAST32_TYPE__ INT32U;
typedef __UINT_FAST64_TYPE__ INT64U;

typedef __INT_FAST8_TYPE__   INT08S;
typedef __INT_FAST16_TYPE__  INT16S;
typedef __INT_FAST32_TYPE__  INT32S;
typedef __INT_FAST64_TYPE__  INT64S;


namespace GLOBAL_CONSTS
{
    extern const QString MapExtensionWithDot;
    extern const INT08U MaximumMapFileNameSizeWithoutExtension;
    extern const QString ProgramHomeDirectory;
    extern const QSettings::Scope Scope;
    extern const QString Organization;
    extern const QString Application;
}

namespace GLOBAL_VARS
{
    enum LayerTypes { Universe, Galaxy, System, Planet };

    extern QString MapDefaultDirectory;

    extern double ScaleFactorIn;
    extern double ScaleFactorOut;

    extern Qt::DockWidgetArea MyCommonToolsDockWidgetArea;
    extern INT16U MyCommonToolsDockWidgetAreaX;
    extern INT16U MyCommonToolsDockWidgetAreaY;

    extern bool MainWindowIsMaximized;
    extern INT16U MainWindowX;
    extern INT16U MainWindowY;
    extern INT16U MainWindowWidth;
    extern INT16U MainWindowHeight;
}

#endif // GLOBAL


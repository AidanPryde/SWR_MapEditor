#include "main\global.h"

///
/// GLOBAL_CONSTS
///
const QString GLOBAL_CONSTS::MapExtensionWithDot = ".mm";
const INT08U GLOBAL_CONSTS::MaximumMapFileNameSizeWithoutExtension = 14 - MapExtensionWithDot.size();
const QString GLOBAL_CONSTS::ProgramHomeDirectory = QDir::currentPath();
const QSettings::Scope GLOBAL_CONSTS::Scope = QSettings::UserScope;
const QString GLOBAL_CONSTS::Organization = "PPP";
const QString GLOBAL_CONSTS::Application = "Star Wars: Rebellion 2";

///
/// GLOBAL_VARS
///
QString GLOBAL_VARS::MapDefaultDirectory = "";

double GLOBAL_VARS::ScaleFactorIn = 0;
double GLOBAL_VARS::ScaleFactorOut = 0;

Qt::DockWidgetArea GLOBAL_VARS::MyCommonToolsDockWidgetArea = Qt::RightDockWidgetArea;
INT16U GLOBAL_VARS::MyCommonToolsDockWidgetAreaX = 0;
INT16U GLOBAL_VARS::MyCommonToolsDockWidgetAreaY = 0;

bool GLOBAL_VARS::MainWindowIsMaximized = true;
INT16U GLOBAL_VARS::MainWindowX = 0;
INT16U GLOBAL_VARS::MainWindowY = 0;
INT16U GLOBAL_VARS::MainWindowWidth = 600;
INT16U GLOBAL_VARS::MainWindowHeight = 400;


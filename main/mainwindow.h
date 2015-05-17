#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "logic\logicmap.h"
#include "view\viewgraphicsview.h"
#include "view\viewgraphicsscene.h"
#include "view/viewgalaxy.h"
#include "view/viewsystem.h"

#include <QMainWindow>
#include <QMenu>
#include <QAction>

class QSettings;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void ActionNewMapClicked();
    void ActionNewGalaxyClicked();
    void ActionOpenMapClicked();
    void ActionOpenGalaxyClicked();
    void ActionOpenRecentClicked();
    void ActionSaveMapClicked();
    void ActionSaveMapAsClicked();
    void ActionSaveAllMapClicked();
    void ActionCloseMapClicked();
    void ActionCloseAllMapClicked();
    void ActionExitClicked();

    void ActionUndoClicked();
    void ActionRedoClicked();
    void ActionCutClicked();
    void ActionCopyClicked();
    void ActionPasteClicked();
    void ActionSelectAllClicked();
    void ActionSearchClicked();

    void ActionMapToolBarClicked();
    void ActionGalaxyToolBarClicked();
    void ActionOptionClicked();

    void ActionInfoClicked();
    void ActionReportBugClicked();
    void ActionAboutMapEditorClicked();
    void ActionAboutQTClicked();

private:
    Q_DISABLE_COPY(MainWindow)

    void LoadGlobalVariables();
    void SaveGlobalVariables();


    QMenu MenuFile;
        QMenu MenuNew;
            QAction ActionNewMap;
            QAction ActionNewGalaxy;
        QMenu MenuOpen;
            QAction ActionOpenMap;
            QAction ActionOpenGalaxy;
        QMenu MenuOpenRecent;
            QList<QAction *> listActionsOpenRecent;
        QAction ActionSaveMap;
        QAction ActionSaveMapAs;
        QAction ActionSaveAllMap;
        QAction ActionCloseMap;
        QAction ActionCloseAllMap;
        QAction ActionExit;
    QMenu MenuEdit;
        QAction ActionUndo;
        QAction ActionRedo;
        QAction ActionCut;
        QAction ActionCopy;
        QAction ActionPaste;
        QAction ActionSelectAll;
        QAction ActionSearch;
    QMenu MenuTools;
        QMenu MenuGetToolBar;
            QAction ActionMapToolBar;
            QAction ActionGalaxyToolBar;
        QAction ActionOption;
    QMenu MenuHelp;
        QAction ActionInfo;
        QAction ActionReportBug;
        QAction ActionAboutMapEditor;
        QAction ActionAboutQT;

    ViewGraphicsView* GraphicsView;
    ViewGraphicsScene* GraphicsScene;
    //ViewToolsDockWidget* MapToolsDockWidget;

    LogicMap *currentLogicMap;
    QList<LogicMap *> mapOpenedList;

    QSettings* editorSettings;

};

#endif // MAINWINDOW_H

#include "main\mainwindow.h"
#include "view\viewnewmapdialog.h"
#include "main\global.h"

#include <QMenuBar>
#include <QSettings>
#include <QFileDialog>
#include <QMessageBox>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      MenuFile(tr("&File"), menuBar()),
          MenuNew(tr("&New"), &MenuFile),
              ActionNewMap(tr("&Map"), &MenuNew),
              ActionNewGalaxy(tr("&Galaxy"), &MenuNew),
          MenuOpen(tr("&Open"), &MenuFile),
              ActionOpenMap(tr("&Map"), &MenuOpen),
              ActionOpenGalaxy(tr("&Galaxy"), &MenuOpen),
          MenuOpenRecent(tr("&Open Recent"), &MenuFile),
              ActionSaveMap(tr("&Save ..."), &MenuFile),
              ActionSaveMapAs(tr("&Save ... As"), &MenuFile),
              ActionSaveAllMap(tr("&Save All"), &MenuFile),
              ActionCloseMap(tr("&Close ..."), &MenuFile),
              ActionCloseAllMap(tr("&Close All"), &MenuFile),
              ActionExit(tr("&Exit"), &MenuFile),
      MenuEdit(tr("&Edit"), menuBar()),
          ActionUndo(tr("&Undo"), &MenuEdit),
          ActionRedo(tr("&Redo"), &MenuEdit),
          ActionCut(tr("&Cut"), &MenuEdit),
          ActionCopy(tr("&Copy"), &MenuEdit),
          ActionPaste(tr("&Paste"), &MenuEdit),
          ActionSelectAll(tr("&Select All"), &MenuEdit),
          ActionSearch(tr("&Search"), &MenuEdit),
      MenuTools(tr("&Tools"), menuBar()),
      MenuGetToolBar(tr("&Tool Bars"), menuBar()),
          ActionMapToolBar(tr("&Common Tool Bar"), &MenuGetToolBar),
          ActionGalaxyToolBar(tr("&Galaxy Tool Bar"), &MenuGetToolBar),
          ActionOption(tr("&Options"), &MenuTools),
      MenuHelp(tr("&Help"), menuBar()),
          ActionInfo(tr("&Information"), &MenuHelp),
          ActionReportBug(tr("&Report Bug"), &MenuHelp),
          ActionAboutMapEditor(tr("&About Map Editor"), &MenuHelp),
          ActionAboutQT(tr("&About QT"), &MenuHelp)/*,
          MapGraphicsView(nullptr),
          MapGraphicsScene(nullptr),
          MapToolsDockWidget(nullptr)*/

{
    this->setWindowFlags(Qt::Window);
    this->setWindowTitle(tr("My Game Map Editor"));

    LoadGlobalVariables();

    if(GLOBAL_VARS::MainWindowIsMaximized)
    {
        setWindowState(Qt::WindowMaximized);
    }
    else
    {
        this->setGeometry(GLOBAL_VARS::MainWindowX, GLOBAL_VARS::MainWindowY, GLOBAL_VARS::MainWindowWidth, GLOBAL_VARS::MainWindowHeight);
    }

    this->menuBar()->addMenu(&MenuFile);
        MenuFile.addMenu(&MenuNew);
            MenuNew.addAction(&ActionNewMap);
                connect(&ActionNewMap, SIGNAL(triggered()), this, SLOT(ActionNewMapClicked()));

            MenuNew.addAction(&ActionNewGalaxy);
                connect(&ActionNewGalaxy, SIGNAL(triggered()), this, SLOT(ActionNewGalaxyClicked()));

        MenuFile.addSeparator();
        MenuFile.addMenu(&MenuOpen);
            MenuOpen.addAction(&ActionOpenMap);
                connect(&ActionOpenMap, SIGNAL(triggered()), this, SLOT(ActionOpenMapClicked()));

            MenuOpen.addAction(&ActionOpenGalaxy);
                connect(&ActionOpenGalaxy, SIGNAL(triggered()), this, SLOT(ActionOpenGalaxyClicked()));

        MenuFile.addMenu(&MenuOpenRecent);
            if(listActionsOpenRecent.isEmpty()) { MenuOpenRecent.setDisabled(true); }

            MenuOpenRecent.addActions(listActionsOpenRecent);
        MenuFile.addSeparator();
        MenuFile.addAction(&ActionSaveMap);
            connect(&ActionSaveMap, SIGNAL(triggered()), this, SLOT(ActionSaveMapClicked()));
            ActionSaveMap.setDisabled(true);

        MenuFile.addAction(&ActionSaveMapAs);
            connect(&ActionSaveMap, SIGNAL(triggered()), this, SLOT(ActionSaveMapClicked()));
            ActionSaveMapAs.setDisabled(true);

        MenuFile.addAction(&ActionSaveAllMap);
            connect(&ActionSaveAllMap, SIGNAL(triggered()), this, SLOT(ActionSaveAllMapClicked()));
            ActionSaveAllMap.setDisabled(true);

        MenuFile.addSeparator();
        MenuFile.addAction(&ActionCloseMap);
            connect(&ActionCloseMap, SIGNAL(triggered()), this, SLOT(ActionCloseMapClicked()));
            ActionCloseMap.setDisabled(true);

        MenuFile.addAction(&ActionCloseAllMap);
            connect(&ActionCloseAllMap, SIGNAL(triggered()), this, SLOT(ActionCloseAllMapClicked()));
            ActionCloseAllMap.setDisabled(true);

        MenuFile.addSeparator();
        MenuFile.addAction(&ActionExit);
            connect(&ActionExit, SIGNAL(triggered()), this, SLOT(ActionExitClicked()));

    this->menuBar()->addMenu(&MenuEdit);
        MenuEdit.addAction(&ActionUndo);
            connect(&ActionUndo, SIGNAL(triggered()), this, SLOT(ActionUndoClicked()));
            ActionUndo.setDisabled(true);

        MenuEdit.addAction(&ActionRedo);
            connect(&ActionRedo, SIGNAL(triggered()), this, SLOT(ActionRedoClicked()));
            ActionRedo.setDisabled(true);

        MenuEdit.addSeparator();
        MenuEdit.addAction(&ActionCut);
            connect(&ActionCut, SIGNAL(triggered()), this, SLOT(ActionCutClicked()));
            ActionCut.setDisabled(true);

        MenuEdit.addAction(&ActionCopy);
            connect(&ActionCopy, SIGNAL(triggered()), this, SLOT(ActionCopyClicked()));
            ActionCopy.setDisabled(true);

        MenuEdit.addAction(&ActionPaste);
            connect(&ActionPaste, SIGNAL(triggered()), this, SLOT(ActionPasteClicked()));
            ActionPaste.setDisabled(true);

        MenuEdit.addSeparator();
        MenuEdit.addAction(&ActionSelectAll);
            connect(&ActionSelectAll, SIGNAL(triggered()), this, SLOT(ActionSelectAllClicked()));
            ActionSelectAll.setDisabled(true);

        MenuEdit.addSeparator();
        MenuEdit.addAction(&ActionSearch);
            connect(&ActionSearch, SIGNAL(triggered()), this, SLOT(ActionSearchClicked()));
            ActionSearch.setDisabled(true);

    this->menuBar()->addMenu(&MenuTools);
        MenuTools.addMenu(&MenuGetToolBar);
            MenuGetToolBar.addAction(&ActionMapToolBar);
                ActionMapToolBar.setDisabled(true);
                connect(&ActionMapToolBar, SIGNAL(triggered()), this, SLOT(ActionMapToolBarClicked()));

            MenuGetToolBar.addAction(&ActionGalaxyToolBar);
                ActionGalaxyToolBar.setDisabled(true);
                connect(&ActionGalaxyToolBar, SIGNAL(triggered()), this, SLOT(ActionGalaxyToolBarClicked()));

        MenuTools.addSeparator();
        MenuTools.addAction(&ActionOption);
            connect(&ActionOption, SIGNAL(triggered()), this, SLOT(ActionOptionClicked()));

    this->menuBar()->addMenu(&MenuHelp);
        MenuHelp.addAction(&ActionInfo);
            connect(&ActionInfo, SIGNAL(triggered()), this, SLOT(ActionInfoClicked()));

        MenuHelp.addSeparator();
        MenuHelp.addAction(&ActionReportBug);
            connect(&ActionReportBug, SIGNAL(triggered()), this, SLOT(ActionReportBugClicked()));

        MenuHelp.addSeparator();
        MenuHelp.addAction(&ActionAboutMapEditor);
            connect(&ActionAboutMapEditor, SIGNAL(triggered()), this, SLOT(ActionAboutMapEditorClicked()));

        MenuHelp.addAction(&ActionAboutQT);
            connect(&ActionAboutQT, SIGNAL(triggered()), this, SLOT(ActionAboutQTClicked()));
}

MainWindow::~MainWindow()
{
    if(this->isMaximized())
    {
        GLOBAL_VARS::MainWindowIsMaximized = true;
    }
    else
    {
        GLOBAL_VARS::MainWindowIsMaximized = false;
        Q_ASSERT(this->geometry().x() > -1 || this->geometry().x() < 65537);
        GLOBAL_VARS::MainWindowX = static_cast<INT16U>(this->geometry().x());
        Q_ASSERT(this->geometry().y() > -1 || this->geometry().y() < 65537);
        GLOBAL_VARS::MainWindowY = static_cast<INT16U>(this->geometry().y());
        Q_ASSERT(this->geometry().width() > -1 || this->geometry().x() < 65537);
        GLOBAL_VARS::MainWindowWidth = static_cast<INT16U>(this->geometry().width());
        Q_ASSERT(this->geometry().height() > -1 || this->geometry().y() < 65537);
        GLOBAL_VARS::MainWindowHeight = static_cast<INT16U>(this->geometry().height());
    }

    SaveGlobalVariables();
}

void MainWindow::LoadGlobalVariables()
{
    editorSettings = new QSettings(QSettings::NativeFormat, GLOBAL_CONSTS::Scope, GLOBAL_CONSTS::Organization, GLOBAL_CONSTS::Application, nullptr);

    GLOBAL_VARS::MapDefaultDirectory = editorSettings->value("mapdefaultdirectory", GLOBAL_CONSTS::ProgramHomeDirectory).toString();

    GLOBAL_VARS::ScaleFactorIn = editorSettings->value("scalefactorin", 1.15).toDouble();
    GLOBAL_VARS::ScaleFactorOut = 1.0 / GLOBAL_VARS::ScaleFactorIn;

    Q_ASSERT(editorSettings->value("mycommontoolsdockwidgetarea", Qt::RightDockWidgetArea).toInt() > -1 || editorSettings->value("mycommontoolsdockwidgetarea", Qt::RightDockWidgetArea).toInt() < 16);
    GLOBAL_VARS::MyCommonToolsDockWidgetArea = static_cast<Qt::DockWidgetArea>(editorSettings->value("mycommontoolsdockwidgetarea", Qt::RightDockWidgetArea).toInt());
    if(GLOBAL_VARS::MyCommonToolsDockWidgetArea == Qt::NoDockWidgetArea)
    {
        Q_ASSERT(editorSettings->value("mycommontoolsdockwidgetareax", 0).toInt() > -1 || editorSettings->value("mycommontoolsdockwidgetareax", 0).toInt() < 65537);
        GLOBAL_VARS::MyCommonToolsDockWidgetAreaX = static_cast<INT16U>(editorSettings->value("mycommontoolsdockwidgetareax", 0).toInt());
        Q_ASSERT(editorSettings->value("mycommontoolsdockwidgetareay", 0).toInt() > -1 || editorSettings->value("mycommontoolsdockwidgetareay", 0).toInt() < 65537);
        GLOBAL_VARS::MyCommonToolsDockWidgetAreaY = static_cast<INT16U>(editorSettings->value("mycommontoolsdockwidgetareay", 0).toInt());
    }

    GLOBAL_VARS::MainWindowIsMaximized = editorSettings->value("mainwindowismaximized", true).toBool();
    if(!GLOBAL_VARS::MainWindowIsMaximized)
    {
        Q_ASSERT(editorSettings->value("mainwindowx", 0).toInt() > -1 || editorSettings->value("mainwindowx", 0).toInt() < 65537);
        GLOBAL_VARS::MainWindowX = static_cast<INT16U>(editorSettings->value("mainwindowx", 0).toInt());
        Q_ASSERT(editorSettings->value("mainwindowy", 0).toInt() > -1 || editorSettings->value("mainwindowy", 0).toInt() < 65537);
        GLOBAL_VARS::MainWindowY = static_cast<INT16U>(editorSettings->value("mainwindowy", 0).toInt());
        Q_ASSERT(editorSettings->value("mainwindowwidth", 600).toInt() > -1 || editorSettings->value("mainwindowwidth", 600).toInt() < 65537);
        GLOBAL_VARS::MainWindowWidth = static_cast<INT16U>(editorSettings->value("mainwindowwidth", 600).toInt());
        Q_ASSERT(editorSettings->value("mainwindowheight", 400).toInt() > -1 || editorSettings->value("mainwindowheight", 400).toInt() < 65537);
        GLOBAL_VARS::MainWindowHeight = static_cast<INT16U>(editorSettings->value("mainwindowheight", 400).toInt());
    }
}

void MainWindow::ActionNewMapClicked()
{
    ViewNewMapDialog newMapDialog(this);
    if(newMapDialog.exec() == QDialog::Accepted)
    {
        QFile* currentOpenMapFile = newMapDialog.GetFile();
        //create default gameLOGIC
        currentLogicMap = new LogicMap(currentOpenMapFile);

        QVBoxLayout * VBLayout = new QVBoxLayout();
        QHBoxLayout * HBLayout = new QHBoxLayout();
        QHBoxLayout * HBLayout_2 = new QHBoxLayout();
        QPushButton * PButton_1 = new QPushButton("scene +10");
        QPushButton * PButton_2 = new QPushButton("scene -10");
        QPushButton * PButton_3 = new QPushButton("view min +10");
        QPushButton * PButton_4 = new QPushButton("view min -10");
        QPushButton * PButton_5 = new QPushButton("view max +10");
        QPushButton * PButton_6 = new QPushButton("view max -10");

        GraphicsView = new ViewGraphicsView(this);

        GraphicsScene = new ViewGraphicsScene(this);
        GraphicsView->setScene(GraphicsScene);


        HBLayout->addWidget(PButton_1);
        //connect(PButton_1, SIGNAL(clicked()), MapGraphicsScene, SLOT(debug_1()));
        HBLayout->addWidget(PButton_2);
        //connect(PButton_2, SIGNAL(clicked()), MapGraphicsScene, SLOT(debug_2()));
        HBLayout->addWidget(PButton_3);
        //connect(PButton_3, SIGNAL(clicked()), MapGraphicsView, SLOT(debug_1()));
        HBLayout->addWidget(PButton_4);
        //connect(PButton_4, SIGNAL(clicked()), MapGraphicsView, SLOT(debug_2()));
        HBLayout->addWidget(PButton_5);
        //connect(PButton_5, SIGNAL(clicked()), MapGraphicsView, SLOT(debug_3()));
        HBLayout->addWidget(PButton_6);
        //connect(PButton_6, SIGNAL(clicked()), MapGraphicsView, SLOT(debug_4()));

        QLineEdit * lEdit1 = new QLineEdit();
        //connect(MapGraphicsView, SIGNAL(debug_signal(QString)), lEdit1, SLOT(setText(QString)));
        QLineEdit * lEdit2 = new QLineEdit();
        //connect(MapGraphicsScene, SIGNAL(debug_signal(QString)), lEdit2, SLOT(setText(QString)));
        HBLayout_2->addWidget(lEdit1);
        HBLayout_2->addWidget(lEdit2);

        VBLayout->addLayout(HBLayout);
        VBLayout->addLayout(HBLayout_2);

        VBLayout->addWidget(GraphicsView);

        QWidget * QCWidget = new QWidget(this);
        QCWidget->setLayout(VBLayout);
        setCentralWidget(QCWidget);


        /*if(MapToolsDockWidget == nullptr)
        {
            MapToolsDockWidget = new MyMapToolsDockWidget(MapGraphicsView, this);
        }
        MapToolsDockWidget->show();*/


    }
}

void MainWindow::ActionNewGalaxyClicked()
{

}

void MainWindow::ActionOpenMapClicked()
{
    //TODO Is there opened map? y-> Is everything saved? n-> Do we want to save all of it?
    QString fileNamePath = QFileDialog::getOpenFileName(this,
                                                        tr("Open map ..."),
                                                        GLOBAL_VARS::MapDefaultDirectory,
                                                        tr("Map (*.mm)"));
    QFile* currentOpenMapFile = new QFile(fileNamePath);
    if(currentOpenMapFile->open(QIODevice::ReadWrite))
    {
        //load gameLOGIC

    }
    else
    {
        QMessageBox::warning(this,
                             tr("Worning ..."),
                             tr("The file '%1' can not be opened.").arg(fileNamePath));
    }
}

void MainWindow::ActionOpenGalaxyClicked()
{

}

void MainWindow::ActionOpenRecentClicked()
{

}

void MainWindow::ActionSaveMapClicked()
{

}

void MainWindow::ActionSaveMapAsClicked()
{

}

void MainWindow::ActionSaveAllMapClicked()
{

}

void MainWindow::ActionCloseMapClicked()
{

}

void MainWindow::ActionCloseAllMapClicked()
{

}

void MainWindow::ActionExitClicked()
{
    //TODO Is evrything saved?
    close();
}

void MainWindow::ActionUndoClicked()
{

}

void MainWindow::ActionRedoClicked()
{

}

void MainWindow::ActionCutClicked()
{

}

void MainWindow::ActionCopyClicked()
{

}

void MainWindow::ActionPasteClicked()
{

}

void MainWindow::ActionSelectAllClicked()
{

}

void MainWindow::ActionSearchClicked()
{

}

void MainWindow::ActionGalaxyToolBarClicked()
{

}

void MainWindow::ActionMapToolBarClicked()
{

}

void MainWindow::ActionOptionClicked()
{

}

void MainWindow::ActionInfoClicked()
{

}

void MainWindow::ActionReportBugClicked()
{

}

void MainWindow::ActionAboutMapEditorClicked()
{

}

void MainWindow::ActionAboutQTClicked()
{
    QMessageBox::aboutQt(this, tr("About QT ..."));
}


void MainWindow::SaveGlobalVariables()
{
    editorSettings->setValue("mapdefaultdirectory", GLOBAL_VARS::MapDefaultDirectory);

    editorSettings->setValue("scalefactorin", GLOBAL_VARS::ScaleFactorIn);

    editorSettings->setValue("mycommontoolsdockwidgetarea", GLOBAL_VARS::MyCommonToolsDockWidgetArea);
    editorSettings->setValue("mycommontoolsdockwidgetareax", GLOBAL_VARS::MyCommonToolsDockWidgetAreaX);
    editorSettings->setValue("mycommontoolsdockwidgetareay", GLOBAL_VARS::MyCommonToolsDockWidgetAreaY);

    editorSettings->setValue("mainwindowismaximized", GLOBAL_VARS::MainWindowIsMaximized);
    editorSettings->setValue("mainwindowx", GLOBAL_VARS::MainWindowX);
    editorSettings->setValue("mainwindowy", GLOBAL_VARS::MainWindowY);
    editorSettings->setValue("mainwindowwidth", GLOBAL_VARS::MainWindowWidth);
    editorSettings->setValue("mainwindowheight", GLOBAL_VARS::MainWindowHeight);

}

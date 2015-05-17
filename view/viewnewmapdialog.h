#ifndef VIEWNEWMAPDIALOG_H
#define VIEWNEWMAPDIALOG_H

#include <QDialog>

#include <QVBoxLayout>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

class QFile;

class ViewNewMapDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewNewMapDialog(QWidget *parent = 0);

    QFile* GetFile();

private slots:
    void PButtonFileDirectoryBrowserClicked();
    void PButtonOkClicked();
    void PButtonCancelClicked();

private:

    Q_DISABLE_COPY(ViewNewMapDialog)

    bool CheckFileName(QString fileNameWithoutExtension);

    QVBoxLayout VBoxLayout;
        QFormLayout FormLayout;
            QHBoxLayout HBoxLayoutFileName;
                QLineEdit LineEditFileName;
                QLabel LabelFileNameExtension;
            QHBoxLayout HBoxLayoutFileDirectory;
                QLineEdit LineEditFileDirectory;
                QPushButton PButtonFileDirectoryBrowser;
        QHBoxLayout HBoxLayoutButtons;
            QPushButton PButtonOk;
            QPushButton PButtonCancel;

    QFile* File;
};

#endif // VIEWNEWMAPDIALOG_H

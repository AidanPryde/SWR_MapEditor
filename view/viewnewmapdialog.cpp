#include "view\viewnewmapdialog.h"
#include "main\global.h"

#include <QFileDialog>
#include <QMessageBox>

ViewNewMapDialog::ViewNewMapDialog(QWidget *parent) :
    QDialog(parent),
    VBoxLayout(this),
    LabelFileNameExtension(GLOBAL_CONSTS::MapExtensionWithDot),
    LineEditFileDirectory(GLOBAL_VARS::MapDefaultDirectory),
    PButtonFileDirectoryBrowser(tr("&Browser")),
    PButtonOk(tr("&Ok")),
    PButtonCancel(tr("&Cancel")),
    File(nullptr)
{
    setWindowTitle(tr("Create new map ..."));

    VBoxLayout.addLayout(&FormLayout);
        FormLayout.addRow(tr("Name: "), &HBoxLayoutFileName);
            HBoxLayoutFileName.addWidget(&LineEditFileName);
            HBoxLayoutFileName.addWidget(&LabelFileNameExtension);
        FormLayout.addRow(tr("Directory: "), &HBoxLayoutFileDirectory);
            HBoxLayoutFileDirectory.addWidget(&LineEditFileDirectory);
            HBoxLayoutFileDirectory.addWidget(&PButtonFileDirectoryBrowser);
                connect(&PButtonFileDirectoryBrowser, SIGNAL(clicked()), this, SLOT(PButtonFileDirectoryBrowserClicked()));

    VBoxLayout.addStretch();
    VBoxLayout.addLayout(&HBoxLayoutButtons);
        HBoxLayoutButtons.addStretch();
        HBoxLayoutButtons.addWidget(&PButtonOk);
            connect(&PButtonOk, SIGNAL(clicked()), this, SLOT(PButtonOkClicked()));

        HBoxLayoutButtons.addWidget(&PButtonCancel);
            connect(&PButtonCancel, SIGNAL(clicked()), this, SLOT(PButtonCancelClicked()));


    setLayout(&VBoxLayout);
}

QFile* ViewNewMapDialog::GetFile()
{
    return File;
}

void ViewNewMapDialog::PButtonFileDirectoryBrowserClicked()
{
    QString dirNamePath = QFileDialog::getExistingDirectory(this,
                                                    tr("Open Directory"),
                                                    GLOBAL_VARS::MapDefaultDirectory,
                                                    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(!dirNamePath.isNull())
    {
       LineEditFileDirectory.setText(dirNamePath);
       GLOBAL_VARS::MapDefaultDirectory = dirNamePath;
    }
}

void ViewNewMapDialog::PButtonOkClicked()
{
    if(QDir(LineEditFileDirectory.text()).exists())
    {
        if(CheckFileName(LineEditFileName.text()))
        {
            GLOBAL_VARS::MapDefaultDirectory = LineEditFileDirectory.text();
            const QString fileNamePath = QDir::toNativeSeparators(GLOBAL_VARS::MapDefaultDirectory + '/' + LineEditFileName.text() + GLOBAL_CONSTS::MapExtensionWithDot);
            File = new QFile(fileNamePath);
            QIODevice::OpenMode openModeFlag = QIODevice::ReadWrite;
            if(File->exists())
            {
                if(QMessageBox::Yes == QMessageBox::question(this,
                                                             tr("Are you sure ...?"),
                                                             tr("Do you want to overwrite the existing '%1' file?").arg(fileNamePath)))
                {
                    openModeFlag |= QIODevice::Truncate;
                }
                else
                {
                    return;
                }

            }
            if(File->open(openModeFlag))
            {
                accept();
            }
            else
            {
                QMessageBox::warning(this,
                                     tr("Worning ..."),
                                     tr("The file '%1' can not be created. Probably no permission or enougth space.").arg(fileNamePath));
            }
        }
    }
    else
    {
        QMessageBox::warning(this,
                             tr("Worning ..."),
                             tr("The directory '%1' is not exist.").arg(LineEditFileDirectory.text()));
    }
}

void ViewNewMapDialog::PButtonCancelClicked()
{
    reject();
}

bool ViewNewMapDialog::CheckFileName(QString fileNameWithoutExtension)
{
    if(fileNameWithoutExtension.isEmpty())
    {
        QMessageBox::warning(this, tr("Warning ..."), tr("No file name was set."));
        return false;
    }
    if(fileNameWithoutExtension.size() > GLOBAL_CONSTS::MaximumMapFileNameSizeWithoutExtension)
    {
        QMessageBox::warning(this,
                             tr("Warning ..."),
                             tr("Your file name is too long. Maximum length is %1, yours length is %2.")\
                                .arg( QString::number( GLOBAL_CONSTS::MaximumMapFileNameSizeWithoutExtension ),\
                                      QString::number( fileNameWithoutExtension.size() ) ));
        return false;
    }
    if(fileNameWithoutExtension.at(0) == '-')
    {
        QMessageBox::warning(this, tr("Warning ..."), tr("File name first charachter can not be '-'."));
        return false;
    }
    for(QString::Iterator it = fileNameWithoutExtension.begin(); it != fileNameWithoutExtension.end(); ++it)
    {
        if(!(it->isLetterOrNumber()))
        {
            if(it->cell() != '.' && it->cell() != '_' && it->cell() != '-')
            {
                QMessageBox::warning(this, tr("Warning ..."), tr("File name can not contain '%1' charachter.").arg(*it));
                return false;
            }
        }
    }
    return true;
}

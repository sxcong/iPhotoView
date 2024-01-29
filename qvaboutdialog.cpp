#include "qvaboutdialog.h"
#include "ui_qvaboutdialog.h"

#include <QFontDatabase>
#include <QJsonDocument>
#include <QDebug>
const float VERSION = 0.1f;

QVAboutDialog::QVAboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QVAboutDialog)
{
    ui->setupUi(this);
    qDebug()<<"QVAboutDialog::QVAboutDialog";

    latestVersionNum = 0.1;

    //setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(windowFlags() & (~Qt::WindowContextHelpButtonHint | Qt::CustomizeWindowHint));
    setWindowModality(Qt::ApplicationModal);

    // add fonts
    QFontDatabase::addApplicationFont(":/fonts/Lato-Light.ttf");
    QFontDatabase::addApplicationFont(":/fonts/Lato-Regular.ttf");

    int modifier = 0;
    //set main title font
#ifdef Q_OS_MACOS
    const QFont font1 = QFont("Lato", 96, QFont::Light);
    modifier = 4;
#else
    const QFont font1 = QFont("Lato", 72, QFont::Light);
#endif
    ui->logoLabel->setFont(font1);

    //set subtitle font & text
    QFont font2 = QFont("Lato", 18 + modifier);
    font2.setStyleName("Regular");
    QString subtitleText = tr("version %1").arg(QString::number(VERSION, 'f', 1));
    // If this is a nightly build, display the build number
#ifdef NIGHTLY
        subtitleText = tr("Nightly %1").arg(QT_STRINGIFY(NIGHTLY));
#endif
    ui->subtitleLabel->setFont(font2);
    ui->subtitleLabel->setText(subtitleText);

    //set update font & text
    QFont font3 = QFont("Lato", 10 + modifier);
    font3.setStyleName("Regular");
    ui->updateLabel->setFont(font3);
    ui->updateLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->updateLabel->setOpenExternalLinks(true);

    //set infolabel2 font, text, and properties
    QFont font4 = QFont("Lato", 8 + modifier);
    font4.setStyleName("Regular");
    const QString labelText2 = tr("Built with Qt %1 (%2)<br>"
                                  R"(Source code available under GPLv3 on <a style="color: #03A9F4; text-decoration:none;" href="https://github.com/jurplel/qView">GitHub</a><br>)"
                                  "Icon glyph created by Guilhem from the Noun Project<br>"
                                  "Copyright © %3 jurplel and qView contributors")
                                  .arg(QT_VERSION_STR, QSysInfo::buildCpuArchitecture(), "2018-2023");

    ui->infoLabel2->setFont(font4);
    ui->infoLabel2->setText(labelText2);

    ui->infoLabel2->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->infoLabel2->setOpenExternalLinks(true);

    if (latestVersionNum < 0.0)
    {
        latestVersionNum = 0.0;
    }

    const QString labelText3 = tr("A Qt-based photo viewer that concentrates on what photographers need.<br>"
                                  R"(c) 2010-2018 Stefan Hundhammer Stefan.Hundhammer@gmx.de <a style="color: #03A9F4; text-decoration:none;" href="https://github.com/shundhammer/qphotoview">GitHub</a><br>)"
                                  "Target Platforms: Linux, BSD, Unix-like systems<br>"
                                  "License: GPL V2<br>"
                                  "Status: Alpha (see below)<br>"
                                  "Updated: 2018-07-12<br>");

    ui->infoLabel3->setFont(font4);
    ui->infoLabel3->setText(labelText3);
    ui->infoLabel3->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->infoLabel3->setOpenExternalLinks(true);


    updateText();
}

QVAboutDialog::~QVAboutDialog()
{
    delete ui;
}

void QVAboutDialog::updateText()
{
    QString updateText = tr("Checking for updates...");
    if (latestVersionNum > VERSION)
    {
        //: %1 is a version number e.g. "4.0 update available"
        updateText = tr("%1 update available").arg(QString::number(latestVersionNum, 'f', 1));
    }
    else if (latestVersionNum > 0.0)
    {
        updateText = tr("No updates available");
    }
    else if (latestVersionNum < 0.0)
    {
        updateText = tr("Error checking for updates");
    }
    ui->updateLabel->setText(updateText +
                             R"(<br><a style="color: #03A9F4; text-decoration:none;" href="https://interversehq.com/qview/">interversehq.com/qview</a>)"
                             R"(<br><a style="color: #03A9F4; text-decoration:none;" href="https://github.com/shundhammer/qphotoview/">github.com/shundhammer/qphotoview</a>)");
}

double QVAboutDialog::getLatestVersionNum() const
{
    return latestVersionNum;
}

void QVAboutDialog::setLatestVersionNum(double value)
{
    latestVersionNum = value;
    updateText();
}

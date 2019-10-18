#include <QDir>
#include <QDebug>
#include <QPalette>
#include <QStandardPaths>
#include <QStyleFactory>
#include <QSqlDatabase>

#include <Application.h>
#include <Dao/ProfileDao.h>
#include <Entities/Profile.h>


Application::Application(int &argc, char **argv)
    : QApplication(argc, argv)
{

}

bool Application::init()
{
    initializePalette();
    initializeStorage();

    if (!openConnection()) {
        return false;
    }

    initProfile();

    return true;
}

void Application::initializePalette()
{
    setStyle(QStyleFactory::create("fusion"));
    QPalette palette;
    palette.setColor(QPalette::Window, QColor("#323232"));
    palette.setColor(QPalette::WindowText, Qt::white);
    palette.setColor(QPalette::Base, QColor("#202020"));
    palette.setColor(QPalette::AlternateBase, QColor("#202020"));
    palette.setColor(QPalette::ToolTipBase, Qt::white);
    palette.setColor(QPalette::ToolTipText, Qt::white);
    palette.setColor(QPalette::Text, QColor("#F9F871"));
    palette.setColor(QPalette::Button, QColor("#323232"));
    palette.setColor(QPalette::ButtonText, QColor("#FFBA6A"));
    palette.setColor(QPalette::BrightText, Qt::red);

    palette.setColor(QPalette::Highlight, QColor("#323232"));
    palette.setColor(QPalette::HighlightedText, Qt::black);
    setPalette(palette);
}

bool Application::openConnection()
{
    qDebug()  <<  QSqlDatabase::drivers();
    QSqlDatabase m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(dbFilePath);

    return m_db.open();
}

void Application::initProfile()
{
    QVariant stored;
    ProfileDao pd;
    Profile *p = pd.get(1);
    stored.setValue(p);
    setProperty("profile", stored);
}

void Application::initializeStorage()
{
    QDir appDataLocation = QDir(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
    dbFilePath = appDataLocation.filePath("db.sqlite");

    if (!appDataLocation.exists()) {
        appDataLocation.mkpath(".");
    }

    qDebug() << "DB file path: " + dbFilePath;

    if (!QFileInfo::exists(dbFilePath)) {
        qDebug() << "DB file doesn't exist. Copying default one from resources.";
        QFile::copy(":/static/db.sqlite", dbFilePath);
        QFile::setPermissions(dbFilePath, QFileDevice::ReadOwner|QFileDevice::WriteOwner);
    }
}


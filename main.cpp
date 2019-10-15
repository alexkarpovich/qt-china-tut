#include <QApplication>
#include <QFileInfo>
#include <QStandardPaths>
#include <QDebug>
#include <QDir>
#include <QStyleFactory>
#include <QSqlDatabase>

#include "Views/MainWindow.h"

void initializePalette(QApplication &a) {
    a.setStyle(QStyleFactory::create("fusion"));
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
    a.setPalette(palette);
}

bool connectToDatabase(QString path) {
    qDebug()  <<  QSqlDatabase::drivers();
    QSqlDatabase m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    return m_db.open();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    initializePalette(a);
    QDir appDataLocation = QDir(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
    QString dbFilePath = appDataLocation.filePath("db.sqlite");

    if (!appDataLocation.exists()) {
        appDataLocation.mkpath(".");
    }

    qDebug() << "DB file path: " + dbFilePath;

    if (!QFileInfo::exists(dbFilePath)) {
        qDebug() << "DB file doesn't exist. Copying default one from resources.";
        QFile::copy(":/static/db.sqlite", dbFilePath);
        QFile::setPermissions(dbFilePath, QFileDevice::ReadOwner|QFileDevice::WriteOwner);
    }

    if (!connectToDatabase(dbFilePath)) {
        return 1;
    }

    MainWindow w;
    w.show();
    return a.exec();
}

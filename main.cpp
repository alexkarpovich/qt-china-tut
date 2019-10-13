#include <QApplication>
#include <QFileInfo>
#include <QStandardPaths>
#include <QDebug>
#include <QDir>
#include <QStyleFactory>

#include "dbmanager.h"
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
        QFile::copy(":/static/app.db", dbFilePath);
        QFile::setPermissions(dbFilePath, QFileDevice::ReadOwner|QFileDevice::WriteOwner);
    }

    DbManager* dbm = new DbManager(dbFilePath);

    if (!dbm->openConnection()) {
        return 1;
    }

    MainWindow w;
    w.setDbManager(dbm);
    w.show();
    return a.exec();
}

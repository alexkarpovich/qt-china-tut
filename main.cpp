#include "dbmanager.h"
#include "mainwindow.h"

#include <QApplication>
#include <QFileInfo>
#include <QStandardPaths>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString dbFilePath = QStandardPaths::locate(QStandardPaths::AppDataLocation, "app.db");
    qDebug() << "DB file path: " + dbFilePath;

    if (!QFileInfo::exists(dbFilePath)) {
        qDebug() << "DB file doesn't exist. Copying default one from resources.";
        QFile::copy(":/static/app.db", dbFilePath);
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

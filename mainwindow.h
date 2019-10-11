#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dbmanager.h"

#include <QMainWindow>
#include <QWidget>
#include <QStackedWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    DbManager* m_db;
    QWidget* rootWidget;
    QStackedWidget* pagesWidget;
    int pageIndex = 0;

    void initWorkspace();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setDbManager(DbManager* dbManager);
};
#endif // MAINWINDOW_H

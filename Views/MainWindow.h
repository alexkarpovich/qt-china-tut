#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dbmanager.h"

#include <QMainWindow>
#include <QWidget>
#include <QStackedWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    enum ViewStates {
        ManagementState = 0
    };

    DbManager* m_db;
    QWidget* rootWidget;
    QStackedWidget* views;
    ViewStates viewState = ManagementState;

    void initWorkspace();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setDbManager(DbManager* dbManager);
};

#endif // MAINWINDOW_H

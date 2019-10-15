#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QStackedWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    enum ViewStates {
        ManagementState = 0
    };

    QWidget* rootWidget;
    QStackedWidget* views;
    ViewStates viewState = ManagementState;

    void initWorkspace();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};

#endif // MAINWINDOW_H

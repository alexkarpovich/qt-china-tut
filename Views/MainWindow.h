#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>

#include "PageSwitch.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

    QWidget* rootWidget;
    PageSwitch* views;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};

#endif // MAINWINDOW_H

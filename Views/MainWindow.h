#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>

#include "PageView.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

    QWidget* rootWidget;
    PageView* page;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};

#endif // MAINWINDOW_H

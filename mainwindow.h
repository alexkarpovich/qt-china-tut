#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QStackedWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QWidget* rootWidget;
    QStackedWidget* pagesWidget;
    int pageIndex = 0;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initWorkspace();
};
#endif // MAINWINDOW_H

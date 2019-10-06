#include "grouplistpage.h"
#include "mainwindow.h"

#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    rootWidget = new QWidget(this);
    pagesWidget = new QStackedWidget;
    QHBoxLayout* rootLayout = new QHBoxLayout;
    rootLayout->addWidget(pagesWidget);
    rootWidget->setFixedSize(640, 480);
    rootWidget->setLayout(rootLayout);
    setCentralWidget(rootWidget);
    initWorkspace();
}

MainWindow::~MainWindow()
{
}

void MainWindow::initWorkspace()
{
    GroupListPage* glPage = new GroupListPage;
    pagesWidget->addWidget(glPage);
    pagesWidget->setCurrentIndex(pageIndex);
}


#include "grouplistpage.h"
#include "mainwindow.h"

#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    rootWidget = new QWidget(this);
    pagesWidget = new QStackedWidget;    
    QHBoxLayout* rootLayout = new QHBoxLayout;
    QHBoxLayout* pagesLayout = new QHBoxLayout;
    pagesLayout->addWidget(pagesWidget);
    rootLayout->addItem(pagesLayout);
    rootLayout->setMargin(0);
    rootWidget->setLayout(rootLayout);
    resize(640, 480);
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

void MainWindow::setDbManager(DbManager *dbManager)
{
    m_db = dbManager;
}


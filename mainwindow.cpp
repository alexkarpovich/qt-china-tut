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
    initPalette();
    initWorkspace();
}

MainWindow::~MainWindow()
{
}

void MainWindow::initPalette()
{
    QPalette pal(palette());
    QBrush brush(QColor(70, 70, 70, 255));
    brush.setStyle(Qt::SolidPattern);
    pal.setBrush(QPalette::Active, QPalette::Base, brush);
    QBrush brush1(QColor(50, 50, 50, 255));
    brush1.setStyle(Qt::SolidPattern);
    pal.setBrush(QPalette::Active, QPalette::Window, brush1);
    pal.setBrush(QPalette::Inactive, QPalette::Base, brush);
    pal.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    pal.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    pal.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    pal.setBrush(QPalette::Active, QPalette::Button, brush);
    setPalette(pal);
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


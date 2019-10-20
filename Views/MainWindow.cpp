#include <QHBoxLayout>

#include <Views/MainWindow.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    rootWidget = new QWidget(this);
    views = new PageSwitch;
    QHBoxLayout* rootLayout = new QHBoxLayout;
    rootLayout->addWidget(views);
    rootLayout->setMargin(0);
    rootWidget->setLayout(rootLayout);
    resize(740, 600);
    setCentralWidget(rootWidget);
}

MainWindow::~MainWindow()
{
}


#include <QHBoxLayout>

#include <Views/MainWindow.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    rootWidget = new QWidget(this);
    page = new PageView;
    QHBoxLayout* rootLayout = new QHBoxLayout;
    rootLayout->addWidget(page);
    rootLayout->setMargin(0);
    rootWidget->setLayout(rootLayout);
    resize(740, 600);
    setCentralWidget(rootWidget);
}

MainWindow::~MainWindow()
{
}


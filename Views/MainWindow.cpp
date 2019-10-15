#include <QHBoxLayout>

#include <Views/MainWindow.h>
#include <Views/ManagementView.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    rootWidget = new QWidget(this);
    views = new QStackedWidget;
    QHBoxLayout* rootLayout = new QHBoxLayout;
    QHBoxLayout* viewsLayout = new QHBoxLayout;
    viewsLayout->addWidget(views);
    rootLayout->addLayout(viewsLayout);
    rootLayout->setMargin(0);
    rootWidget->setLayout(rootLayout);
    resize(740, 600);
    setCentralWidget(rootWidget);
    initWorkspace();
}

MainWindow::~MainWindow()
{
}

void MainWindow::initWorkspace()
{
    ManagementView* managementView = new ManagementView;
    views->addWidget(managementView);
    views->setCurrentIndex(viewState);
}


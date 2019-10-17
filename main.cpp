#include <Application.h>
#include <Views/MainWindow.h>


int main(int argc, char *argv[])
{
    Application app(argc, argv);

    if (!app.init()) {
        return 1;
    }

    MainWindow w;
    w.show();
    return app.exec();
}

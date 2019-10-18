#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>


class Application : public QApplication
{
    Q_OBJECT
    QString dbFilePath;

    void initializePalette();
    void initializeStorage();
    bool openConnection();
    void initProfile();
public:
    Application(int &argc, char **argv);
    bool init();
    int x = 1;
};

#endif // APPLICATION_H

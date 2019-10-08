#ifndef GROUPLISTWIDGET_H
#define GROUPLISTWIDGET_H

#include <QListWidget>
#include <QWidget>

#include <models/group.h>

class GroupListWidget : public QListWidget
{
    Q_OBJECT
    QList<Group*> groupList;
public:
    explicit GroupListWidget(QWidget *parent = nullptr);
    void addGroup();

signals:

public slots:
};

#endif // GROUPLISTWIDGET_H

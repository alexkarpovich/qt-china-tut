#ifndef GROUPLISTWIDGET_H
#define GROUPLISTWIDGET_H

#include <QListWidget>
#include <QWidget>

class GroupListWidget : public QListWidget
{
    Q_OBJECT
public:
    explicit GroupListWidget(QWidget *parent = nullptr);
    void addGroup();

signals:

public slots:
};

#endif // GROUPLISTWIDGET_H

#ifndef WORDLISTITEM_H
#define WORDLISTITEM_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class WordListItem : public QWidget
{
    Q_OBJECT
    QLabel* wordLabel;
    QPushButton* editButton;
    QPushButton* removeButton;
public:
    explicit WordListItem(QWidget *parent = nullptr);
    void setWordText(const QString text);
signals:

public slots:
};

#endif // WORDLISTITEM_H

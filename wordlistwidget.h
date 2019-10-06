#ifndef WORDLISTWIDGET_H
#define WORDLISTWIDGET_H

#include <QListWidget>

class WordListWidget : public QListWidget
{
public:
    WordListWidget(QWidget *parent = nullptr);
    void appendWord(const QString text);
};

#endif // WORDLISTWIDGET_H

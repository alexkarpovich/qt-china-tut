#ifndef TRANSLATIONEDITOR_H
#define TRANSLATIONEDITOR_H

#include <QLineEdit>
#include <QWidget>

#include <Dao/WordDao.h>

class TranslationEditor : public QWidget
{
    Q_OBJECT
    int wordid;
    WordDao *wordDao;
    QLineEdit *translationInput;

public:
    explicit TranslationEditor(int wordid, QWidget *parent = nullptr);

signals:

public slots:
};

#endif // TRANSLATIONEDITOR_H

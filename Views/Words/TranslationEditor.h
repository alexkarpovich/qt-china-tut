#ifndef TRANSLATIONEDITOR_H
#define TRANSLATIONEDITOR_H

#include <QLineEdit>
#include <QListView>
#include <QWidget>

#include <Dao/WordDao.h>
#include <Models/TranslationModel.h>

class TranslationEditor : public QWidget
{
    Q_OBJECT
    QList<int> groupids;
    int wordid;
    QList<Word *> options;
    WordDao *wordDao;
    QLineEdit *translationInput;
    QListView *optionsView;
    TranslationModel *translationModel;

public:
    explicit TranslationEditor(QList<int> groupids, int wordid, QWidget *parent = nullptr);

signals:

public slots:
    void onTranslationInputReturnPressed();
};

#endif // TRANSLATIONEDITOR_H

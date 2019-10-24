#ifndef CARDMODEL_H
#define CARDMODEL_H

#include <QObject>
#include <Dao/TrainingDao.h>
#include <Dao/WordDao.h>

class CardModel : public QObject
{
    Q_OBJECT

    TrainingDao *trainingDao;
    WordDao *wordDao;
public:
    explicit CardModel(QObject *parent = nullptr);
    Word *getForeignWord() const;
    void setForeignWord(Word *value);

    Word *getNativeWord() const;
    void setNativeWord(Word *value);

    bool isComplete() const;
    void setCompletance(bool value);

public slots:
    void next();
    void complete();
    void reset();

signals:
    void dataChanged();

private:
    bool m_isComplete;
    Training *training;
    Word *foreignWord;
    Word *nativeWord;

};

#endif // CARDMODEL_H

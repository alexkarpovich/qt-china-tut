#ifndef CARDMODEL_H
#define CARDMODEL_H

#include <QObject>
#include <Dao/TrainingDao.h>

class CardModel : public QObject
{
    Q_OBJECT

    TrainingDao *trainingDao;
public:
    enum State {
        StateAsk = 0,
        StateDetail = 1
    };
    explicit CardModel(QObject *parent = nullptr);
    Word *getForeignWord() const;
    void setForeignWord(Word *value);

    Word *getNativeWord() const;
    void setNativeWord(Word *value);

    State getState() const;

public slots:
    void setState(const State &value);
    void next();
    void complete();

signals:
    void dataChanged();

private:
    State state;
    Word *foreignWord;
    Word *nativeWord;

};

#endif // CARDMODEL_H

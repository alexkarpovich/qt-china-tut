#ifndef TRAININGMODEL_H
#define TRAININGMODEL_H

#include <QObject>
#include <Dao/TrainingDao.h>

class TrainingModel  : public QObject
{
    Q_OBJECT

    TrainingDao *trainingDao;
public:
    TrainingModel(QList<int> groupids, Training::Type type, QObject *parent = nullptr);

    Training *training() const;
    void setTraining(Training *training);

    Word *foreigh() const;
    void setForeigh(Word *foreigh);

    Word *native() const;
    void setNative(Word *native);

    void nextWord();
    void completeWord();

    void reset();
    bool isComplete();
    void setCompleteness(bool value);
    bool isNew();

private:
    Training *m_training;
    Word *m_foreigh;
    Word *m_native;
    bool m_isComplete;
    bool m_isNew;

signals:
    void dataChanged();
};

#endif // TRAININGMODEL_H

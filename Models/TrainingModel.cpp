#include "TrainingModel.h"

TrainingModel::TrainingModel(QList<int> groupids, Training::Type type, QObject *parent)
    : QObject(parent), trainingDao(new TrainingDao)
{
    Training *trn = new Training;
    trn->setType(type);
    m_training = trainingDao->getOrCreate(groupids, trn);
}

Training *TrainingModel::training() const
{
    return m_training;
}

void TrainingModel::setTraining(Training *training)
{
    m_training = training;
}

Word *TrainingModel::foreigh() const
{
    return m_foreigh;
}

void TrainingModel::setForeigh(Word *foreigh)
{
    m_foreigh = foreigh;
}

Word *TrainingModel::native() const
{
    return m_native;
}

void TrainingModel::setNative(Word *native)
{
    m_native = native;
}

void TrainingModel::nextWord()
{
    m_native = trainingDao->nextTranslation(m_training->getId());

    if (!m_native) {
        setCompleteness(true);
        return;
    } else {
        m_foreigh = trainingDao->translationWords(m_training->getId(), m_native->getId()).first();
    }

    emit dataChanged();
}

void TrainingModel::completeWord()
{
    trainingDao->completeWord(m_training->getId(), m_native->getId());
    nextWord();
}

void TrainingModel::reset()
{
    trainingDao->reset(m_training->getId());
    setCompleteness(false);
    nextWord();
}

bool TrainingModel::hasCompleted()
{
    return m_hasCompleted;
}

void TrainingModel::setCompleteness(bool value)
{
    m_hasCompleted = value;
}

bool TrainingModel::hasCanceled()
{
    return m_hasCanceled;
}
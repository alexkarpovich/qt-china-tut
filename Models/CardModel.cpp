#include "CardModel.h"

CardModel::CardModel(QObject *parent)
    : QObject(parent), trainingDao(new TrainingDao), wordDao(new WordDao), m_isComplete(false)
{
    training = trainingDao->latest();
    next();
}

Word *CardModel::getForeignWord() const
{
    return foreignWord;
}

void CardModel::setForeignWord(Word *value)
{
    foreignWord = value;
}

Word *CardModel::getNativeWord() const
{
    return nativeWord;
}

void CardModel::setNativeWord(Word *value)
{
    nativeWord = value;
}

void CardModel::next()
{
    nativeWord = trainingDao->nextTranslation(training->getId());

    if (!nativeWord) {
        setCompletance(true);
        return;
    }

    foreignWord = trainingDao->translationWords(training->getId(), nativeWord->getId()).first();
    emit dataChanged();
}

void CardModel::complete()
{
    trainingDao->completeWord(training->getId(), nativeWord->getId());
    next();
}

void CardModel::reset()
{
    trainingDao->reset(training->getId());
    next();
}

bool CardModel::isComplete() const
{
    return m_isComplete;
}

void CardModel::setCompletance(bool value)
{
    m_isComplete = value;
    emit dataChanged();
}


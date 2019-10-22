#include "CardModel.h"

CardModel::CardModel(QObject *parent)
    : QObject(parent), state(StateAsk), trainingDao(new TrainingDao)
{
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
    nativeWord = trainingDao->nextTranslation(trainingDao->latest()->getId());
    emit dataChanged();
}

void CardModel::complete()
{

}

CardModel::State CardModel::getState() const
{
    return state;
}

void CardModel::setState(const State &value)
{
    state = value;
    emit dataChanged();
}

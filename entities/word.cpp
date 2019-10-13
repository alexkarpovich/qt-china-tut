#include "Word.h"

int Word::getId() const
{
    return id;
}

void Word::setId(int value)
{
    id = value;
}

QString Word::getZh() const
{
    return zh;
}

void Word::setZh(const QString &value)
{
    zh = value;
}

QString Word::getRu() const
{
    return ru;
}

void Word::setRu(const QString &value)
{
    ru = value;
}

QString Word::getTranscription() const
{
    return transcription;
}

void Word::setTranscription(const QString &value)
{
    transcription = value;
}

int Word::getStatus() const
{
    return status;
}

void Word::setStatus(int value)
{
    status = value;
}

int Word::getGroupId() const
{
    return groupId;
}

void Word::setGroupId(int value)
{
    groupId = value;
}

Word::Word()
{
    
}

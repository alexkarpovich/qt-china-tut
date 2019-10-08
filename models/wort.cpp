#include "wort.h"

int Wort::getId() const
{
    return id;
}

void Wort::setId(int value)
{
    id = value;
}

QString Wort::getZh() const
{
    return zh;
}

void Wort::setZh(const QString &value)
{
    zh = value;
}

QString Wort::getRu() const
{
    return ru;
}

void Wort::setRu(const QString &value)
{
    ru = value;
}

QString Wort::getTranscription() const
{
    return transcription;
}

void Wort::setTranscription(const QString &value)
{
    transcription = value;
}

int Wort::getStatus() const
{
    return status;
}

void Wort::setStatus(int value)
{
    status = value;
}

Wort::Wort()
{

}

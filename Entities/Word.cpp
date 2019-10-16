#include "Word.h"

QString Word::getTranscription() const
{
    return transcription;
}

void Word::setTranscription(const QString &value)
{
    transcription = value;
}

int Word::getId() const
{
    return id;
}

void Word::setId(int value)
{
    id = value;
}

QString Word::codeString(Language code)
{
    switch (code) {
    case LangZh: return "zh";
    case LangRu: return "ru";
    }

    return "";
}

Word::Word()
{
    text = "";
    transcription = "";
}

QString Word::getText() const
{
    return text;
}

void Word::setText(const QString &value)
{
    text = value;
}

#include "Language.h"

QString Language::getWord() const
{
    return word;
}

void Language::setWord(const QString &value)
{
    word = value;
}

QString Language::getTranscription() const
{
    return transcription;
}

void Language::setTranscription(const QString &value)
{
    transcription = value;
}

int Language::getId() const
{
    return id;
}

void Language::setId(int value)
{
    id = value;
}

QString Language::codeString(Language::Code code)
{
    switch (code) {
    case CodeZh: return "zh";
    case CodeRu: return "ru";
    }

    return "";
}

Language::Language()
{

}

#ifndef WORD_H
#define WORD_H

#include <QString>

class Word
{
    int id;
    QString text;
    QString transcription;
public:
    enum Language {
        LangZh = 0,
        LangRu = 1,
    };
    Word();
    QString getTranscription() const;
    void setTranscription(const QString &value);
    int getId() const;
    void setId(int value);
    static QString codeString(Language code);
    QString getText() const;
    void setText(const QString &value);
};

#endif // WORD_H

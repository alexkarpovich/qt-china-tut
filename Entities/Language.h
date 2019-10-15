#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <QString>

class Language
{
    int id;
    QString word;
    QString transcription;
public:
    enum Code {
        CodeZh = 0,
        CodeRu = 1,
    };
    Language();
    QString getWord() const;
    void setWord(const QString &value);
    QString getTranscription() const;
    void setTranscription(const QString &value);
    int getId() const;
    void setId(int value);
    static QString codeString(Code code);
};

#endif // LANGUAGE_H

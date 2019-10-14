#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <QString>

class Language
{
    int id;
    QString word;
    QString transcription;
public:
    Language();
    QString getWord() const;
    void setWord(const QString &value);
    QString getTranscription() const;
    void setTranscription(const QString &value);
    int getId() const;
    void setId(int value);
};

#endif // LANGUAGE_H

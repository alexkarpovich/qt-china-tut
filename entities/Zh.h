#ifndef ZH_H
#define ZH_H

#include <QString>

class Zh
{
    int id;
    QString word;
    QString transcriptino;
public:
    Zh();
    QString getWord() const;
    void setWord(const QString &value);
    QString getTranscriptino() const;
    void setTranscriptino(const QString &value);
    int getId() const;
    void setId(int value);
};

#endif // ZH_H

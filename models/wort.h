#ifndef WORT_H
#define WORT_H

#include <QString>

class Wort
{
    int id;
    QString zh;
    QString ru;
    QString transcription;
    int status;
public:
    Wort();
    int getId() const;
    void setId(int value);
    QString getZh() const;
    void setZh(const QString &value);
    QString getRu() const;
    void setRu(const QString &value);
    QString getTranscription() const;
    void setTranscription(const QString &value);
    int getStatus() const;
    void setStatus(int value);
};

#endif // WORT_H

#ifndef WORD_H
#define WORD_H

#include <QString>

class Word
{
    int id;
    int groupId;
    QString zh;
    QString ru;
    QString transcription;
    int status;
public:
    enum Status {
        StatusNew = 0,
        StatusScraped = 1,
        StatusDeleted = 2
    };

    Word();
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
    int getGroupId() const;
    void setGroupId(int value);

};

#endif // WORD_H

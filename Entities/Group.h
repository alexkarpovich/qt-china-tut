#ifndef GROUP_H
#define GROUP_H

#include <QString>

class Group
{
    int id;
    QString name;
    int wordCount;
public:
    Group();
    QString getName() const;
    void setName(const QString &value);
    int getId() const;
    void setId(int value);
    int getWordCount() const;
    void setWordCount(int value);
    void increaseWordCount();
};

#endif // GROUP_H

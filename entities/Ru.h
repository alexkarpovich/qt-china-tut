#ifndef RU_H
#define RU_H

#include <QString>

class Ru
{
    int id;
    QString word;
public:
    Ru();
    int getId() const;
    void setId(int value);
    QString getWord() const;
    void setWord(const QString &value);
};

#endif // RU_H

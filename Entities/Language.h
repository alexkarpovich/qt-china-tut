#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <QString>

class Language
{
    int id;
    QString code;
    QString name;
public:
    Language();
    int getId() const;
    void setId(int value);
    QString getCode() const;
    void setCode(const QString &value);
    QString getName() const;
    void setName(const QString &value);
};

#endif // LANGUAGE_H

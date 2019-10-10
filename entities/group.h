#ifndef GROUP_H
#define GROUP_H

#include <QString>

class Group
{
    int id;
    QString name;
public:
    Group();
    QString getName() const;
    void setName(const QString &value);
    int getId() const;
    void setId(int value);
};

#endif // GROUP_H

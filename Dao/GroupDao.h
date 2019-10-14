#ifndef GROUPDAO_H
#define GROUPDAO_H

#include <QList>
#include <Entities/Group.h>
#define GROUP_TABLE " groups "

class GroupDao
{
public:
    GroupDao();
public:
    QList<Group *> all();
    Group *get(int id);
    Group *create(Group *value);
    void update(Group *value);
    void del(Group *value);
};

#endif // GROUPDAO_H

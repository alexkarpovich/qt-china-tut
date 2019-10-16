#ifndef GROUPDAO_H
#define GROUPDAO_H

#include <QList>
#include <Entities/Group.h>
#include <Entities/Profile.h>
#include <Entities/Word.h>
#define GROUP_TABLE " groups "

class GroupDao
{
    Profile *profile;
public:
    GroupDao();
public:
    QList<Group *> all();
    Group *get(int id);
    Group *create(Group *value);
    Group *create(const QString& name);
    void update(Group *value);
    void del(Group *value);
    QList<Word *> words(int groupid);
    Word *addWord(int groupid, const QString &text);
};

#endif // GROUPDAO_H

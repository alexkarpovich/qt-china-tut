#ifndef PROFILEDAO_H
#define PROFILEDAO_H
#define PROFILE_TABLE " profiles "

#include <QList>
#include <Entities/Profile.h>

class ProfileDao
{
public:
    ProfileDao();
    QList<Profile *> all();
    Profile *get(int id);
    Language *create(Profile *value);
    void update(Profile *value);
    void del(Profile *value);
};

#endif // PROFILEDAO_H

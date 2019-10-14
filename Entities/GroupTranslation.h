#ifndef GROUPTRANSLATION_H
#define GROUPTRANSLATION_H

#include <Entities/Group.h>
#include <Entities/Translation.h>

class GroupTranslation
{
    Group *group;
    Translation *translation;
public:
    GroupTranslation();
    Group *getGroup() const;
    void setGroup(Group *value);
    Translation *getTranslation() const;
    void setTranslation(Translation *value);
};

#endif // GROUPTRANSLATION_H

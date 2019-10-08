#include "models/groupword.h"

Wort *GroupWord::getWord() const
{
    return word;
}

void GroupWord::setWord(Wort *value)
{
    word = value;
}

int GroupWord::getId() const
{
    return id;
}

void GroupWord::setId(int value)
{
    id = value;
}

Group *GroupWord::getGroup() const
{
    return group;
}

void GroupWord::setGroup(Group *value)
{
    group = value;
}

#ifndef GROUPWORD_H
#define GROUPWORD_H

#include <QString>
#include "group.h"
#include "word.h"

class GroupWord
{
    int id;
    Group* group;
    Word* word;
public:
    GroupWord();
    int getId() const;
    void setId(int value);
    Group *getGroup() const;
    void setGroup(Group *value);
    Word *getWord() const;
    void setWord(Word *value);
};

#endif // GROUPWORD_H

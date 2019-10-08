#ifndef WORD_H
#define WORD_H

#include <QString>
#include "models/group.h"
#include "models/wort.h"

class GroupWord
{
    int id;
    Group* group;
    Wort* word;
public:
    GroupWord();
    int getId() const;
    void setId(int value);
    Group *getGroup() const;
    void setGroup(Group *value);
    Wort *getWord() const;
    void setWord(Wort *value);
};

#endif // WORD_H

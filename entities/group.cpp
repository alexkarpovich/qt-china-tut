#include "Group.h"

int Group::getId() const
{
    return id;
}

void Group::setId(int value)
{
    id = value;
}

int Group::getWordCount() const
{
    return wordCount;
}

void Group::setWordCount(int value)
{
    wordCount = value;
}

Group::Group()
{
    id = 0;
    wordCount = 0;
}

QString Group::getName() const
{
    return name;
}

void Group::setName(const QString &value)
{
    name = value;
}


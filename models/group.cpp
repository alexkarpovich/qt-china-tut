#include "group.h"

int Group::getId() const
{
    return id;
}

void Group::setId(int value)
{
    id = value;
}

Group::Group()
{
}

QString Group::getName() const
{
    return name;
}

void Group::setName(const QString &value)
{
    name = value;
}


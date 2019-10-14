#include "GroupTranslation.h"

Group *GroupTranslation::getGroup() const
{
    return group;
}

void GroupTranslation::setGroup(Group *value)
{
    group = value;
}

Translation *GroupTranslation::getTranslation() const
{
    return translation;
}

void GroupTranslation::setTranslation(Translation *value)
{
    translation = value;
}

GroupTranslation::GroupTranslation()
{

}

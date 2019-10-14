#include "Translation.h"

Language *Translation::getSource() const
{
    return source;
}

void Translation::setSource(Language *value)
{
    source = value;
}

Language *Translation::getDist() const
{
    return dist;
}

void Translation::setDist(Language *value)
{
    dist = value;
}

int Translation::getId() const
{
    return id;
}

void Translation::setId(int value)
{
    id = value;
}

Translation::Translation()
{

}

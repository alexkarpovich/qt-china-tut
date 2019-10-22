#include "Training.h"

Training::Training()
    : type(TypeNtvFgn)
{

}

int Training::getId() const
{
    return id;
}

void Training::setId(int value)
{
    id = value;
}

Training::Type Training::getType() const
{
    return type;
}

void Training::setType(const Type &value)
{
    type = value;
}

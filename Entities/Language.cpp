#include "Language.h"

int Language::getId() const
{
    return id;
}

void Language::setId(int value)
{
    id = value;
}

QString Language::getCode() const
{
    return code;
}

void Language::setCode(const QString &value)
{
    code = value;
}

QString Language::getName() const
{
    return name;
}

void Language::setName(const QString &value)
{
    name = value;
}

Language::Language()
{

}

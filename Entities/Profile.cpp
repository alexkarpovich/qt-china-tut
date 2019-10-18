#include "Profile.h"

int Profile::getId() const
{
    return id;
}

void Profile::setId(int value)
{
    id = value;
}

Language *Profile::getLearningLang() const
{
    return learningLang;
}

void Profile::setLearningLang(Language *value)
{
    learningLang = value;
}

Language *Profile::getNativeLang() const
{
    return nativeLang;
}

void Profile::setNativeLang(Language *value)
{
    nativeLang = value;
}

Profile::Profile()
{

}

Profile::Profile(const Profile &other) :
    id(other.getId()), learningLang(other.getLearningLang()), nativeLang(other.getNativeLang())
{

}

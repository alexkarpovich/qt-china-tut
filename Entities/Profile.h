#ifndef PROFILE_H
#define PROFILE_H

#include <Entities/Language.h>

class Profile
{
    int id;
    Language *learningLang;
    Language *nativeLang;
public:
    Profile();
    int getId() const;
    void setId(int value);
    Language *getLearningLang() const;
    void setLearningLang(Language *value);
    Language *getNativeLang() const;
    void setNativeLang(Language *value);
};

#endif // PROFILE_H

#ifndef PROFILE_H
#define PROFILE_H

#include <QObject>
#include <QVariant>
#include <Entities/Language.h>

class Profile
{
    int id;
    Language *learningLang;
    Language *nativeLang;
public:
    Profile();
    Profile(const Profile &other);
    int getId() const;
    void setId(int value);
    Language *getLearningLang() const;
    void setLearningLang(Language *value);
    Language *getNativeLang() const;
    void setNativeLang(Language *value);
};

Q_DECLARE_METATYPE(Profile);

#endif // PROFILE_H

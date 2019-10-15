#ifndef LANGUAGEDAO_H
#define LANGUAGEDAO_H
#define LANGUAGE_TABLE " languages "

#include <QList>
#include <Entities/Language.h>

class LanguageDao
{
public:
    LanguageDao();
    QList<Language *> all();
    Language *get(int id);
    Language *create(Language *value);
    void update(Language *value);
    void del(Language *value);
};

#endif // LANGUAGEDAO_H

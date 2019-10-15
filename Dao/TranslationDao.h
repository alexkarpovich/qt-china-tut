#ifndef TRANSLATIONDAO_H
#define TRANSLATIONDAO_H
#define TRANSLATION_TABLE " groups "

#include <QList>
#include <Entities/Translation.h>

class TranslationDao
{
public:
    TranslationDao();
    QList<Translation *> all();
    Translation *get(int id);
    Translation *create(Translation *value);
    void update(Translation *value);
    void del(Translation *value);
    QList<Translation *> filterByGroup(int groupid);
};

#endif // TRANSLATIONDAO_H

#ifndef LANGDAO_H
#define LANGDAO_H

#include <QList>
#include <Entities/Language.h>

template<typename T>
class LangDao
{
public:
    LangDao();
    QList<Language *> all();
    Language *get(int id);
    Language *create(Language *value);
    void update(Language *value);
    void del(Language *value);
};

#endif // LANGDAO_H

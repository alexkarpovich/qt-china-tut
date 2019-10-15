#ifndef LANGDAO_H
#define LANGDAO_H

#include <QList>
#include <Entities/Language.h>

class LangDao
{
    Language::Code code;
public:
    LangDao(const Language::Code &code);
    QList<Language *> all();
    Language *get(int id);
    Language *create(Language *value);
    void update(Language *value);
    void del(Language *value);
    void setCode(const Language::Code &value);
};

#endif // LANGDAO_H

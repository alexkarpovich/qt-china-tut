#ifndef WORDDAO_H
#define WORDDAO_H

#include <QList>
#include <Entities/Word.h>

class WordDao
{
    Word::Language code;
public:
    WordDao(const Word::Language &code);
    QList<Word *> all();
    Word *get(int id);
    Word *create(Word *value);
    void update(Word *value);
    void del(Word *value);
    void setCode(const Word::Language &value);
};

#endif // WORDDAO_H

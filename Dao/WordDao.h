#ifndef WORDDAO_H
#define WORDDAO_H

#include <QList>
#include <Entities/Word.h>
#include <Entities/Profile.h>

class WordDao
{
    Profile *profile;
public:
    WordDao();
    QList<Word *> all();
    Word *get(int id);
    Word *getByText(const QString& value);
    Word *create(Word *value);
    void update(Word *value);
    void del(Word *value);
    QList<Word *> translations(int id);
    Word *getTranslationByText(int id, const QString& text);
    Word *createTranslation(int id, Word *wrd);
    Word *addTranslation(int id, const QString& text);
};

#endif // WORDDAO_H

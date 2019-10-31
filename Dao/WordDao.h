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
    Word *createTranslationWord(Word *wrd);
    Word *addTranslation(int groupid, int wordid, const QString& text);
    QMap<int, bool> translationFlags(int groupid, int wordid);
    void updateTranslationFlags(int groupid, int wordid, int twordid, bool value);

};

#endif // WORDDAO_H

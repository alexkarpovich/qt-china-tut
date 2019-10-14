#include "LangDao.h"

template<typename T>
LangDao<T>::LangDao()
{

}

template<typename T>
QList<Language *> LangDao<T>::all()
{
    QList<Language *> langs;

    return langs;
}

template<typename T>
Language *LangDao<T>::get(int id)
{
    return new Language;
}

template<typename T>
Language *LangDao<T>::create(Language *value)
{

}

template<typename T>
void LangDao<T>::update(Language *value)
{

}

template<typename T>
void LangDao<T>::del(Language *value)
{

}

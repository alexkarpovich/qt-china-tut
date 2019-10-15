#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include "WordDao.h"

WordDao::WordDao(const Word::Language &code)
{
    this->code = code;
}

void WordDao::setCode(const Word::Language &value)
{
    code = value;
}

QList<Word *> WordDao::all()
{
    QList<Word *> words;
    QSqlQuery query;
    QString table = Word::codeString(code);
    query.prepare("SELECT * FROM "+ table);

    if (query.exec()) {
        while (query.next()) {
            Word* wrd = new Word;
            wrd->setId(query.value(0).toInt());
            wrd->setText(query.value(1).toString());
            wrd->setTranscription(query.value(2).toString());
            words << wrd;
        }
    }



    return words;
}

Word *WordDao::get(int id)
{
    QSqlQuery query;
    QString table = Word::codeString(code);
    query.prepare("SELECT * FROM " + table + " WHERE id=:id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        Word* wrd = new Word;
        wrd->setId(query.value(0).toInt());
        wrd->setText(query.value(1).toString());
        wrd->setTranscription(query.value(2).toString());

        return wrd;
    }

    return nullptr;
}

Word *WordDao::create(Word *value)
{
    QSqlQuery query;
    QString table = Word::codeString(code);
    query.prepare("INSERT INTO " + table + " (word, transcription) VALUES ((:word), (:transcription))");
    query.bindValue(":word", value->getText());
    query.bindValue(":transcription", value->getTranscription());

    if (query.exec() && query.next()) {
        value->setId(query.lastInsertId().toInt());

        return value;
    }

    return nullptr;
}

void WordDao::update(Word *value)
{
    QSqlQuery query;
    QString table = Word::codeString(code);
    query.prepare("UPDATE" + table + "SET word=:word, transcription=:transcription WHERE id=:id");
    query.bindValue(":id", value->getId());
    query.bindValue(":word", value->getText());
    query.bindValue(":transcription", value->getTranscription());

    if (query.exec() && query.next()) {
        qDebug() << QString("Lang was updated (%1, %2)").arg(QString::number(value->getId()), value->getText());
    } else {
        qDebug() << QString("Lang update error: %s").arg(query.lastError().text());
    }
}

void WordDao::del(Word *value)
{
    QSqlQuery query;
    QString table = Word::codeString(code);

    query.prepare("DELETE FROM" + table + "WHERE id=:id");
    query.bindValue(":id", value->getId());

    if (query.exec() && query.next()) {
        qDebug() << QString("Group (%1, %2) was deleted").arg(QString::number(value->getId()), value->getText());
    } else {
        qDebug() << QString("Group deleting error: %s").arg(query.lastError().text());
    }
}

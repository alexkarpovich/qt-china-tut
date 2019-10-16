#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

#include <Dao/WordDao.h>
#include <Dao/ProfileDao.h>

WordDao::WordDao()
{
    ProfileDao pd;
    profile = pd.get(1);
}

QList<Word *> WordDao::translations(int id)
{
    QList<Word *> list;
    QSqlQuery query;
    QString sql = "SELECT * FROM %1 ln "
                  "LEFT JOIN translations t ON t.src_code=:srcCode AND t.src_id=:srcid "
                  "WHERE t.dst_id=ln.id";
    query.prepare(sql.arg(profile->getNativeLang()->getCode()));
    query.bindValue(":srcid", id);
    query.bindValue(":srcCode", profile->getNativeLang()->getId());

    if (query.exec()) {
        while (query.next()) {
            Word* wrd = new Word;
            wrd->setId(query.value(0).toInt());
            wrd->setText(query.value(1).toString());
            wrd->setTranscription(query.value(2).toString());
            list << wrd;
        }
    }

    return list;
}

Word *WordDao::getTranslationByText(int id, const QString &text)
{
    QSqlQuery query;
    QString sql = "SELECT * FROM %1 WHERE text=:text";
    query.prepare(sql.arg(profile->getNativeLang()->getCode()));
    query.bindValue(":text", text);

    if (query.exec() && query.next()) {
        Word* wrd = new Word;
        wrd->setId(query.value(0).toInt());
        wrd->setText(query.value(1).toString());
        wrd->setTranscription(query.value(2).toString());

        return wrd;
    }

    return nullptr;
}

Word *WordDao::createTranslation(int id, Word *wrd)
{
    QSqlQuery query;
    QString sql = QString("INSERT INTO %1 (text, transcription) VALUES (:text, :transcription)")
        .arg(profile->getNativeLang()->getCode());
    query.prepare(sql);
    query.bindValue(":text", wrd->getText());
    query.bindValue(":transcription", wrd->getTranscription());

    if (query.exec()) {
        wrd->setId(query.lastInsertId().toInt());

        return wrd;
    } else {
        qDebug() << QString("Translation insert error: %s").arg(query.lastError().text());
    }

    return nullptr;
}

Word *WordDao::addTranslation(int id, const QString &text)
{
    if (!getTranslationByText(id, text)) {
        Word *wrd = new Word;
        wrd->setText(text);
        return createTranslation(id, wrd);
    }

    return nullptr;
}

QList<Word *> WordDao::all()
{
    QList<Word *> words;
    QSqlQuery query;
    QString sql = "SELECT * FROM %1";

    if (query.exec(sql.arg(profile->getLearningLang()->getCode()))) {
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
    QString sql = "SELECT * FROM %1 WHERE id=:id";
    query.prepare(sql.arg(profile->getLearningLang()->getCode()));
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

Word *WordDao::getByText(const QString &value)
{
    QSqlQuery query;
    QString sql = "SELECT * FROM %1 WHERE text=:text";
    query.prepare(sql.arg(profile->getLearningLang()->getCode()));
    query.bindValue(":text", value);

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
    QString sql = QString("INSERT INTO %1 (text, transcription) VALUES (:text, :transcription)")
        .arg(profile->getLearningLang()->getCode());
    query.prepare(sql);
    query.bindValue(":text", value->getText());
    query.bindValue(":transcription", value->getTranscription());

    if (query.exec()) {
        value->setId(query.lastInsertId().toInt());

        return value;
    } else {
        qDebug() << QString("Word insert error: %s").arg(query.lastError().text());
    }

    return nullptr;
}

void WordDao::update(Word *value)
{
    QSqlQuery query;
    QString sql = "UPDATE %1 SET text=:text, transcription=:transcription WHERE id=:id";

    query.prepare(sql.arg(profile->getLearningLang()->getCode()));
    query.bindValue(":id", value->getId());
    query.bindValue(":text", value->getText());
    query.bindValue(":transcription", value->getTranscription());

    if (query.exec()) {
        qDebug() << QString("Word was updated (%1, %2)").arg(QString::number(value->getId()), value->getText());
    } else {
        qDebug() << QString("Word update error: %s").arg(query.lastError().text());
    }
}

void WordDao::del(Word *value)
{
    QSqlQuery query;
    QString sql = "DELETE FROM %1 WHERE id=:id";
    query.prepare(sql.arg(profile->getLearningLang()->getCode()));
    query.bindValue(":id", value->getId());

    if (query.exec()) {
        qDebug() << QString("Word (%1, %2) was deleted").arg(QString::number(value->getId()), value->getText());
    } else {
        qDebug() << QString("Word deleting error: %s").arg(query.lastError().text());
    }
}

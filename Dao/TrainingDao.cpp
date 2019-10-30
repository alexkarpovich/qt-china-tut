#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

#include <Application.h>
#include "TrainingDao.h"

TrainingDao::TrainingDao()
{
    profile = qvariant_cast<Profile*>(qGuiApp->property("profile"));
}

Training *TrainingDao::latest()
{
    QSqlQuery query;

    if (query.exec("SELECT * FROM trainings ORDER BY id DESC LIMIT 1") && query.next()) {
        Training *trn = new Training;
        trn->setId(query.value(0).toInt());
        trn->setType(static_cast<Training::Type>(query.value(0).toInt()));

        return trn;
    }

    return nullptr;
}

Training *TrainingDao::get(int trainingid)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM trainings WHERE id=:trainingid");
    query.bindValue(":trainingid", trainingid);

    if (query.exec() && query.next()) {
        Training *trn = new Training;
        trn->setId(query.value(0).toInt());
        trn->setType(static_cast<Training::Type>(query.value(1).toInt()));

        return trn;
    }

    return nullptr;
}

Training *TrainingDao::create(QList<int> groupids, Training *trn)
{
    QSqlQuery query;
    query.prepare("INSERT INTO trainings (type) VALUES(:type)");
    query.bindValue(":type", trn->getType());

    if (query.exec()) {
        trn->setId(query.lastInsertId().toInt());
        QStringList strnums;

        foreach(int id, groupids) {
            strnums << QString::number(id);
        }
        QString sql = QString("INSERT INTO groups_trainings (group_id, training_id) SELECT id, %1 FROM groups WHERE id IN (%2)")
            .arg(QString::number(trn->getId()), strnums.join(","));

        if (!query.exec(sql)) {
            qDebug() << "Training create error: " + query.lastError().text();
        }

        return trn;
    }

    return nullptr;
}

Training *TrainingDao::getOrCreate(QList<int> groupids, Training *trn)
{
    QSqlQuery query;
    QStringList strnum;
    foreach(int id, groupids) {
        strnum << QString::number(id);
    }
    QString sql = "SELECT a.training_id FROM groups_trainings a "
            "WHERE a.group_id IN (%1) AND %2="
                  "(SELECT count(group_id) FROM groups_trainings b WHERE b.training_id=a.training_id) "
            "GROUP BY a.training_id";
    sql = sql.arg(strnum.join(","), QString::number(groupids.size()));
    if (query.exec(sql) && query.next()) {
        int trainingid = query.value(0).toInt();

        return get(trainingid);
    }

    return create(groupids, trn);
}

void TrainingDao::reset(int trainingid)
{
    QSqlQuery query;
    query.prepare("UPDATE trainings_translations SET status=0 WHERE training_id=:trainingid");
    query.bindValue(":trainingid", trainingid);

    if (!query.exec()) {
        qDebug() << "Training reset error: " + query.lastError().text();
    }
}

Word *TrainingDao::nextTranslation(int trainingid)
{
    QSqlQuery query;
    QString sql = "SELECT %1.* FROM %1 "
            "LEFT JOIN translations t on %1.id = t.%1_id "
            "LEFT JOIN groups_translations gtr on t.id = gtr.translation_id "
            "LEFT JOIN groups_trainings gt on gt.group_id=gtr.group_id "
            "LEFT OUTER JOIN trainings_translations tt on tt.training_id=gt.training_id AND t.id = tt.translation_id "
            "WHERE gt.training_id=%2 AND (tt.status ISNULL or tt.status != 1) "
            "GROUP by %1.id "
            "ORDER BY RANDOM() "
            "LIMIT 1";
    sql = sql.arg(profile->getNativeLang()->getCode(), QString::number(trainingid));

    if (query.exec(sql) && query.next()) {
        Word *wrd = new Word;
        wrd->setId(query.value(0).toInt());
        wrd->setText(query.value(1).toString());
        wrd->setTranscription(query.value(2).toString());

        return wrd;
    }

    return nullptr;
}

QList<Word *> TrainingDao::translationWords(int trainingid, int translationid)
{
    QList<Word *> list;
    QSqlQuery query;
    QString sql = "SELECT %1.* FROM %1 "
            "LEFT JOIN translations t ON %1.id = t.%1_id "
            "LEFT JOIN groups_translations gt on t.id = gt.translation_id "
            "LEFT JOIN groups_trainings gtr on gt.group_id=gtr.group_id "
            "WHERE gtr.training_id=%3 AND t.%2_id=%4 "
            "GROUP BY %1.id";
    sql = sql.arg(profile->getLearningLang()->getCode(),
                  profile->getNativeLang()->getCode(),
                  QString::number(trainingid),
                  QString::number(translationid));

    if (query.exec(sql)) {
        while(query.next()) {
            Word *wrd = new Word;
            wrd->setId(query.value(0).toInt());
            wrd->setText(query.value(1).toString());
            wrd->setTranscription(query.value(2).toString());
            list.append(wrd);
        }
    }

    return list;
}

void TrainingDao::completeWord(int trainingid, int wordid)
{
    QSqlQuery query;
    QString sql = "INSERT OR REPLACE INTO trainings_translations (training_id, translation_id, status) "
                  "SELECT gtr.training_id, gt.translation_id, 1 FROM groups_translations gt "
                  "LEFT JOIN translations t on gt.translation_id = t.id "
                  "LEFT JOIN groups_trainings gtr ON gtr.group_id=gt.group_id "
                  "WHERE gtr.training_id=%1 AND t.%2_id=%3";
    sql = sql.arg(QString::number(trainingid), profile->getNativeLang()->getCode(), QString::number(wordid));

    if (!query.exec(sql)) {
        qDebug() << "Training complete error: " + query.lastError().text();
    }
}

bool TrainingDao::isComplete(int trainingid)
{
    QSqlQuery query;
    QString sql = "SELECT 1 FROM "
                "(select count(translation_id) size from trainings_translations where training_id=%1 AND status=1) complete, "
                "(select count(translation_id) size from groups_translations a LEFT JOIN groups_trainings b ON b.group_id=a.group_id WHERE b.training_id=%1) existing "
            "WHERE complete.size = existing.size AND complete.size > 0";
    sql = sql.arg(trainingid);

    if (query.exec(sql) && query.next()) {
        return true;
    } else {
        qDebug() << "Training has completed error: " + query.lastError().text();
    }

    return false;
}

bool TrainingDao::isNew(int trainingid)
{
    QSqlQuery query;
    QString sql = "select exists(select 1 from trainings_translations where training_id=%1 AND status=1)";
    sql = sql.arg(trainingid);

    if (query.exec(sql) && query.next()) {
        return !query.value(0).toBool();
    } else {
        qDebug() << "Training is new error: " + query.lastError().text();
    }

    return false;
}

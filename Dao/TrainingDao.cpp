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

Word *TrainingDao::nextTranslation(int trainingid)
{
    QSqlQuery query;
    QString sql = "SELECT %1.* FROM ru "
            "LEFT JOIN translations t on %1.id = t.%1_id "
            "LEFT JOIN groups_translations gtr on t.id = gtr.translation_id "
            "LEFT JOIN groups_trainings gt on gt.group_id=gtr.group_id "
            "LEFT OUTER JOIN trainings_translations tt on t.id = tt.translation_id "
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

void TrainingDao::completeWord(int trainingid, int wordid)
{

}

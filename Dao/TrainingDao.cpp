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

Training *TrainingDao::create(QList<int> groupids, Training *trn)
{
    QSqlQuery query;
    query.prepare("INSERT INTO trainings (type) VALUES(:type)");
    query.bindValue(":type", trn->getType());

    if (query.exec()) {
        trn->setId(query.lastInsertId().toInt());

        QVariantList groups;
        foreach (int id, groupids) {
            groups << id;
        }

        query.prepare("INSERT INTO groups_trainings (group_id, training_id) "
                      "SELECT (id, :trainingid) FROM groups WHERE id = ANY(:groupids)");
        query.bindValue(":trainingid", trn->getId());
        query.bindValue(":groupids", groups);

        return trn;
    }

    return nullptr;
}

Word *TrainingDao::nextTranslation(int trainingid)
{

}

void TrainingDao::completeWord(int trainingid, int wordid)
{

}

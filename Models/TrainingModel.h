#ifndef TRAININGMODEL_H
#define TRAININGMODEL_H

#include <QObject>
#include <Dao/TrainingDao.h>

class TrainingModel  : public QObject
{

public:
    TrainingModel(QObject *parent = nullptr);

private:
    int m_id;
    Training::Type m_type;
};

#endif // TRAININGMODEL_H

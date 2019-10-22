#ifndef TRAININGDAO_H
#define TRAININGDAO_H

#include <Entities/Profile.h>
#include <Entities/Word.h>
#include <Entities/Training.h>

class TrainingDao
{
    Profile *profile;
public:
    TrainingDao();
    Training *latest();
    Training *create(QList<int> groupids, Training *trn);
    Word *nextTranslation(int trainingid);
    void completeWord(int trainingid, int wordid);

};

#endif // TRAININGDAO_H

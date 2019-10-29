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
    Training *get(int trainingid);
    Training *create(QList<int> groupids, Training *trn);
    Training *getOrCreate(QList<int> groupids, Training *trn);
    void reset(int trainingid);
    Word *nextTranslation(int trainingid);
    QList<Word *> translationWords(int trainingid, int translationid);
    void completeWord(int trainingid, int wordid);
    bool isComplete(int trainingid);
    bool isNew(int trainingid);

};

#endif // TRAININGDAO_H

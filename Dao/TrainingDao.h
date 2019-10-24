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
    void reset(int trainingid);
    Word *nextTranslation(int trainingid);
    QList<Word *> translationWords(int trainingid, int translationid);
    void completeWord(int trainingid, int wordid);

};

#endif // TRAININGDAO_H

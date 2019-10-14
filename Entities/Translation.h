#ifndef TRANSLATION_H
#define TRANSLATION_H

#include <Entities/Language.h>

class Translation
{    
public:
    enum Direction {
        DirectionZhRu = 0,
    };

    Translation();
    Language *getSource() const;
    void setSource(Language *value);
    Language *getDist() const;
    void setDist(Language *value);
    int getId() const;
    void setId(int value);

private:
    int id;
    Language *source;
    Language *dist;
    Direction direction;
};

#endif // TRANSLATION_H

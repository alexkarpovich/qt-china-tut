#ifndef TRANSLATION_H
#define TRANSLATION_H

#include <Entities/Language.h>

class Translation
{    
public:
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
    Language::Code sourceCode;
    Language *dist;
    Language::Code distCode;
};

#endif // TRANSLATION_H

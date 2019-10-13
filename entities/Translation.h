#ifndef TRANSLATION_H
#define TRANSLATION_H


class Translation
{
    enum TranslationType {
        TypeZhRu = 0,
    };

    int id;
    TranslationType type;
public:    
    Translation();
};

#endif // TRANSLATION_H

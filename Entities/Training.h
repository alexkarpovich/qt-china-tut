#ifndef TRAINING_H
#define TRAINING_H


class Training
{    
public:
    enum Type {
        TypeNtvFgn = 0,
        TypeFgnNtv = 1,
        TypeSndFgn = 2,
        TypeSndNtv = 3
    };

    Training();
    int getId() const;
    void setId(int value);

    Type getType() const;
    void setType(const Type &value);

private:
    int id;
    Type type;
};

#endif // TRAINING_H

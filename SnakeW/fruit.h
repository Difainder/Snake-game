#ifndef FRUIT_H
#define FRUIT_H
#include <QPoint>


class Fruit
{
public:
    Fruit(int randomizer);
    QPoint position;
    void place(int randomizer);

private:
    static const int FIELD_W = 64;
    static const int FIELD_H = 32;
    QPoint initPlace(int randomizer);

};

#endif // FRUIT_H

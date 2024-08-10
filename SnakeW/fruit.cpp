#include "fruit.h"
#include <QTime>

Fruit::Fruit(int randomizer)
{
    // Создаём рандомайзер, чтобы поставить фрукт
    QPoint tmp = initPlace(randomizer);
    this->position.setX(tmp.x());
    this->position.setY(tmp.y());
}

QPoint Fruit::initPlace(int randomizer)
{
    QPoint tmp;
    QTime time = QTime::currentTime();
    qsrand(time.msec() + randomizer);
    tmp.setX(qrand() % FIELD_W);
    tmp.setY(qrand() % FIELD_H);
    return tmp;
}

void Fruit::place(int randomizer)
{
    QTime time = QTime::currentTime();
    qsrand(time.msec() + randomizer);
    this->position.setX(qrand() % FIELD_W);
    this->position.setY(qrand() % FIELD_H);
}

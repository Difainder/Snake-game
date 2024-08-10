#ifndef SNAKE_H
#define SNAKE_H
#include <QVector>
#include <QPoint>

class Snake
{
public:
    Snake();
    QVector <QPoint> body;
    enum Directions //Напоминает структуру, элементы имеют тип Directions, элементы нумеруются системой, через эти номера (названия элементов енума) происходит обращение к ним в системе
    {
        Left, Right, Up, Down
    };
    Directions direction;
    void move();
};

#endif // SNAKE_H

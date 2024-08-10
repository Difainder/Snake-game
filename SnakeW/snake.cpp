#include "snake.h"

Snake::Snake()
{
    this->direction = Right;
    this->body.resize(3);
    for (int i = 0; i < 3; i++)
    {
        this->body[i].setX(this->body.size()-i-1);
        this->body[i].setY(0);
    }
}

void Snake::move()
{
    for (int i = this->body.size()-1; i > 0; i--)
        this->body[i] = this->body[i-1];

    switch (direction)
    {
        case Up:    { this->body[0].ry() -= 1; break;}
        case Down:  { this->body[0].ry() += 1; break;}
        case Left:  { this->body[0].rx() -= 1; break;}
        case Right: { this->body[0].rx() += 1; break;}
    }
}

#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QVector>
#include <QPoint>
#include <QKeyEvent>
#include <fruit.h>
#include <snake.h>

class Game : public QWidget
{
public:
    explicit Game(QWidget *parent = nullptr);
    void timerEvent(QTimerEvent*) override; // override нужен для переопределения функции под свои нужды, т.е. для переписывания её поведения
    void keyPressEvent(QKeyEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    int DELAY;
    QString difficultyMode = "";
    void setup();

    static const int CELL_W = 20;  // ширина клетки
    static const int CELL_H = 20;  // высота клетки
    static const int FIELD_W = 64; // количество клеток поля в ширину
    static const int FIELD_H = 32; // количество клеток поля в высоту

    // Константы для рандомайзера, чтобы фрукты создавались в разных позициях
    static const int APPL_SEED = 0;
    static const int KIWI_SEED = 68847658;


private:
    int timerID; //Таймер, который отвечает за отрисовку игрового процесса
    bool inGame; //Продолжается ли игра
    int score;
    Fruit *apple, *kiwi;
    Snake snake;

    void initGame();
    void doDrawing();
    void checkBorders();
    void gameOver();
    void checkFruit();
    void writeToFile(int score);
};

#endif // GAME_H

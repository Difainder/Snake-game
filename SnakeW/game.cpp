#include "game.h"
#include <QDebug>
#include <QPainter>
#include <QTime>
#include <QMessageBox>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTextStream>

Game::Game(QWidget *parent) : QWidget(parent)
{
    initGame();
    this->setFixedSize(CELL_W * FIELD_W, CELL_H * FIELD_H);
    this->setWindowTitle("Змейка | Счёт: " + QString::number(score));
}

void Game::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);

    if (inGame)
    {
        checkFruit();
        snake.move();
        checkBorders();
    }
    this->repaint();
}

void Game::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();

    if ((key == Qt::Key_Up    || key == 'W' || key == 'w') && snake.direction != Snake::Directions::Down ) {snake.direction = Snake::Directions::Up;}
    if ((key == Qt::Key_Down  || key == 'S' || key == 's') && snake.direction != Snake::Directions::Up   ) {snake.direction = Snake::Directions::Down;}
    if ((key == Qt::Key_Left  || key == 'A' || key == 'a') && snake.direction != Snake::Directions::Right) {snake.direction = Snake::Directions::Left;}
    if ((key == Qt::Key_Right || key == 'D' || key == 'd') && snake.direction != Snake::Directions::Left ) {snake.direction = Snake::Directions::Right;}
}

void Game::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    doDrawing();
}

void Game::initGame()
{
    inGame = true;
    score = 0;

    snake = Snake();
    apple = new Fruit(APPL_SEED);
    kiwi = new Fruit(KIWI_SEED);
    timerID = startTimer(DELAY);
}

void Game::doDrawing()
{
    QPainter qp(this);

    if (inGame)
    {
        this->setWindowTitle("Змейка | Счёт: " + QString::number(score));

        /* Рисуем яблоко */
        qp.setBrush(Qt::red);
        qp.drawEllipse(apple->position.x() * CELL_W, apple->position.y() * CELL_H, CELL_W, CELL_H);

        /* Рисуем киви */
        qp.setBrush(Qt::darkYellow);
        qp.drawEllipse(kiwi->position.x() * CELL_W, kiwi->position.y() * CELL_H, CELL_W, CELL_H);


        /* Рисуем змейку */
        for (int i = 0; i < snake.body.size(); i++)
        {
            if(i == 0)
            {
                /* Рисуем голову */
                auto headX = snake.body[0].x();
                auto headY = snake.body[0].y();

                qp.setBrush(Qt::green);
                qp.drawEllipse(headX * CELL_W, headY * CELL_H, CELL_W, CELL_W);
            }
            else
            {
                /* Рисуем тело */
                qp.setBrush(Qt::darkGreen);
                qp.drawEllipse(snake.body[i].x() * CELL_W, snake.body[i].y() * CELL_H, CELL_W, CELL_W);
            }
        }
    }
    else
    {
        gameOver();
    }
}

void Game::writeToFile(int score)
{
    QString fileName = "C:/Users/Dif/Desktop/Qt/Snake/record.txt";
    QFile mFile(fileName);

    if (!mFile.open(QFile::WriteOnly | QFile::Text | QIODevice::Append))
    {
        QMessageBox message;
        message.setText("Произошла ошибка при открытии файла!");
        message.exec();
        close();
    }


    auto time = QTime::currentTime().toString();
    auto date = QDate::currentDate().toString();

    QTextStream out(&mFile);
    out << "| Дата: " + date + " | Время: "+ time + " | Уровень сложности: " + difficultyMode + " | Счёт: " + QString::number(score) + " |\n";
    /* Чистим поток от символов */
    mFile.flush();
    mFile.close();
    close();
}

void Game::checkBorders()
{
    for (int i = 1; i < snake.body.size(); i++)
    {
        if (snake.body[0] == snake.body[i])
            inGame = false;
    }

    if (snake.body[0].x() >= FIELD_W ||
        snake.body[0].y() >= FIELD_H ||
        snake.body[0].x() < 0 ||
        snake.body[0].y() < 0)
        {inGame = false;}

    if (!inGame)
    {
        killTimer(timerID);
    }
}

void Game::gameOver()
{
    QMessageBox message;
    message.setText("Вы проиграли :(\nВаш счёт - " + QString::number(score));
    message.exec();

    writeToFile(score);
}

void Game::checkFruit()
{
    if (snake.body[0] == apple->position)
    {
        snake.body.push_back(QPoint(0,0));
        apple->place(APPL_SEED);
        score += 1;
    }

    if (snake.body[0] == kiwi->position)
    {
        snake.body.push_back(QPoint(0,0));
        snake.body.push_back(QPoint(0,0));
        kiwi->place(KIWI_SEED);
        score += 2;
    }
}

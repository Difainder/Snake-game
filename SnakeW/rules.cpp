#include "rules.h"
#include <QLabel>
#include <QPushButton>
#include <game.h>
#include <mainwindow.h>
#include <QDebug>
#include <QPushButton>

Rules::Rules()
{
    initWindow();
    initDifficultyButtons();
}

void Rules::initWindow()
{
    rulesMenu = new QLabel();
    QString rulesText =
            "\n Правила игры следующие:\n"
            "   1) Игра продолжается, пока змейка не врежется в края окна или в саму себя\n"
            "   2) При поедании яблока змейка увеличивается на 1 кружок, а при поедании киви - на 2; счёт, считается соответсвенно\n"
            "   3) От выбора уровня сложности зависит скорость змейки (лёгкий - медленная, сложный - быстрая)\n"
            "   4) После окончания игры запоминается дата-время-сложность-счёт - информацию обо всех играх можно посмотреть в меню, одноимённом разделе.\n";

    rulesMenu->setFixedSize(1280, 640);
    rulesMenu->setWindowTitle("Змейка");
    rulesMenu->setAlignment(Qt::AlignTop);
    rulesMenu->setText(rulesText);
}

void Rules::initDifficultyButtons()
{
    low    = new QPushButton("Низкая сложность", rulesMenu);
    middle = new QPushButton("Средняя сложность", rulesMenu);
    hard   = new QPushButton("Высокая сложность", rulesMenu);
    back   = new QPushButton("Назад", rulesMenu);

    const int center = rulesMenu->width()/2 - rulesMenu->width()/10;
    const int height = rulesMenu->height();
    const int buttonW = 256;
    const int buttonH = 96;
    const int interval = height / 64;

    const int lowY = height/2 - buttonH/2 - buttonH - interval;
    const int midY = height/2 - buttonH/2;
    const int harY = height/2 + buttonH/2 + interval;
    const int bakX = interval;
    const int bakY = height - buttonH - interval;

    low   ->setGeometry(center, lowY, buttonW, buttonH);
    middle->setGeometry(center, midY, buttonW, buttonH);
    hard  ->setGeometry(center, harY, buttonW, buttonH);
    back  ->setGeometry(bakX,   bakY, buttonW, buttonH);

    connect(low,    &QPushButton::clicked, this, &Rules::lowDifficulty);
    connect(middle, &QPushButton::clicked, this, &Rules::middleDifficulty);
    connect(hard,   &QPushButton::clicked, this, &Rules::hardDifficulty);
    connect(back,   &QPushButton::clicked, this, &Rules::backToMenu);
}

// Кнопки, которые создают игровой процесс с определёнными параметрами уровня сложности
// difficultyMode нужен для запоминания уровня сложности и соответсвутствующей записи в файл со статистикой
// DELAY отвечает за скорость змейки (частоту перерисовки игрового поля): чем она больше - тем медленнее движется змейка
void Rules::lowDifficulty()
{
    rulesMenu->close();
    Game game;
    game.DELAY = 175;
    game.difficultyMode = "Лёгкая";
    game.show();
}

void Rules::middleDifficulty()
{
    rulesMenu->close();
    Game game;
    game.DELAY = 135;
    game.difficultyMode = "Средняя";
    game.show();
}

void Rules::hardDifficulty()
{
    rulesMenu->close();
    Game game;
    game.DELAY = 95;
    game.difficultyMode = "Высокая";
    game.show();
}

void Rules::backToMenu()
{
    rulesMenu->close();
    MainWindow mainWindow;
    mainWindow.menu->show();
}




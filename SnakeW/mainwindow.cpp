#include "mainwindow.h"
#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QFile>
#include <QDebug>
#include <rules.h>
#include <game.h>


MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    initMenu();
    initButtons();
}

void MainWindow::initMenu()
{
    menu = new QWidget(); /* Есть menu, которое надо инициализировать QWidget, т.к. указатель menu никуда не указывает */
    menu->setFixedSize(1280, 640);
    menu->setWindowTitle("Змейка");
}

void MainWindow::initButtons()
{
    play        = new QPushButton("Играть",   menu);
    leaderboard = new QPushButton("Все игры", menu);
    quit        = new QPushButton("Выйти",    menu);

    const int center = menu->width()/2 - menu->width()/10;
    const int height = menu->height();
    const int buttonW = 256;
    const int buttonH = 96;
    const int interval = height / 64;

    const int playY        = height/2 - buttonH/2 - buttonH - interval;
    const int leaderboardY = height/2 - buttonH/2;
    const int quitY        = height/2 + buttonH/2 + interval;

    play->       setGeometry(center, playY,        buttonW, buttonH);
    quit->       setGeometry(center, quitY,        buttonW, buttonH);
    leaderboard->setGeometry(center, leaderboardY, buttonW, buttonH);

    // Какая кнопка/при каком действии посылает сигнал/к какому виджету относится/что происходит после нажатия
    connect(play,        &QPushButton::clicked, this, &MainWindow::handlePlay);
    connect(quit,        &QPushButton::clicked, this, &MainWindow::handleQuit);
    connect(leaderboard, &QPushButton::clicked, this, &MainWindow::handleLeaderboard);
}

void MainWindow::handleQuit()
{
    QApplication::quit();
}

void MainWindow::handlePlay()
{
    menu->close();
    Rules rules;
    rules.rulesMenu->show();
}

void MainWindow::handleLeaderboard()
{
    QString data = readLeaderboardData();
    auto table = new QLabel();

    table->setWindowTitle("Статистика по всем играм");
    table->setFixedSize(540, 1000);
    table->setText(data);
    table->setAlignment(Qt::AlignTop);
    table->show();
}

QString MainWindow::readLeaderboardData() //Получаем данные из файла статистики
{
    QString fileName = "C:/Users/Dif/Desktop/Qt/Snake/record.txt";
    QFile mFile(fileName);

    //Проверка на корректное открытие файла
    if(!mFile.exists() || !mFile.open(QIODevice::ReadOnly))
    {
        qCritical() << "Возникла проблема с файлом чтения!";
    }

    //Читаем данные в строку data
    QTextStream reading(&mFile);
    auto data = reading.readAll();
    mFile.close();
    return data;
}



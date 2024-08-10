#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QPushButton>
#include <QLabel>


class MainWindow : public QWidget
{
public:
    QWidget *menu;
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void handleQuit();
    void handlePlay();
    void handleLeaderboard();

private:
    QPushButton *play;
    QPushButton *quit;
    QPushButton *leaderboard;

    void initMenu();
    void initButtons();
    QString readLeaderboardData();
};

#endif // MAINWINDOW_H

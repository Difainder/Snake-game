#ifndef MAINMENU_H
#define MAINMENU_H
#include <QWidget>
#include <QPushButton>


class MainMenu : public QWidget
{
public:
    MainMenu();
    QWidget *mainWindow;
    QPushButton *play, *quit, *leaderboard;
};

#endif // MAINMENU_H

#include <QApplication>
#include <mainwindow.h>
#include <QWidget>
#include <game.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv); /* Создаём приложение с аргументами из командной строки */
    //MainWindow mainWindow; mainWindow.menu->show(); /* Создаём главное меню */
    Game game; game.show();

    return app.exec();
}

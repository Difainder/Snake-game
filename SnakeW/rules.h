#ifndef RULES_H
#define RULES_H
#include <QLabel>
#include <QPushButton>

class Rules : public QLabel
{
public:
    QLabel *rulesMenu;
    Rules();

private slots:
    void lowDifficulty();
    void middleDifficulty();
    void hardDifficulty();
    void backToMenu();

private:
    QPushButton *low;
    QPushButton *middle;
    QPushButton *hard;
    QPushButton *back;

    void initWindow();
    void initDifficultyButtons();
};

#endif // RULES_H

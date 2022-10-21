#ifndef GAME_H
#define GAME_H
#include <QPushButton>
#include <QMessageBox>
class Game
{
public:
    Game();
    void newGame();
    bool clickOnField(int num);
    int checkVictory();
    int getStep();
private:
    int field[9];
    int step;
};

#endif // GAME_H

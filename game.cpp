#include "game.h"

Game::Game()
{
    for(int i=0; i<9; i++)
    {
        this->field[i] = 0;
    }

    this->step = 1;
}

void Game::newGame()
{
    for(int i=0; i<9; i++)
    {
        this->field[i] = 0;

    }
    this->step = 1;
}

int Game::getStep()
{
    return this->step;
}

bool Game::clickOnField(int num)
{
    this->field[num] = step;
    step *= -1;
    int resCheckVictory = checkVictory();
    if(resCheckVictory != 0)
    {
        QMessageBox win_window;
        if(resCheckVictory == 1) {
            win_window.setText("The crosses won!");
        } else if (resCheckVictory == -1) {
            win_window.setText("The noughts won!");
        } else if (resCheckVictory == 2) {
            win_window.setText("Draw");
        }
        win_window.setStandardButtons(QMessageBox::Ok);
        switch (win_window.exec())
        {
        case QMessageBox::Ok:
            // вызов сигнала о очистке поля
            // connect(...)
            emit
            break;
        }
        return true;
    }
    return false;
}

int Game::checkVictory()
{
    int flag=0;                                                                     // check this pos:
    if (this->field[0] != 0 &&
        ((this->field[0] == this->field[1] && this->field[1] == this->field[2]) ||  // ***  *--  *--
        (this->field[0] == this->field[3] && this->field[3] == this->field[6]) ||   // ---  *--  -*-
        (this->field[0] == this->field[4] && this->field[4] == this->field[8])))    // ---  *--  --*
    {
        if (this->field[0] == 1){
            flag = 1;
        } else {
            flag = -1;
        }
    }
    else if ( (this->field[1] != 0 && this->field[1] == this->field[4] && this->field[4] == this->field[7]) ||  // -*-  ---
              (this->field[3] != 0 && this->field[3] == this->field[4] && this->field[4] == this->field[5]))    // -*-  ***
    {                                                                                                           // -*-  ---
        if (this->field[4] == 1){
            flag = 1;
        } else {
            flag = -1;
        }
    }
    else  if (this->field[2] != 0 &&
              ((this->field[2] == this->field[4] && this->field[4] == this->field[6]) ||  // --*  --*
              (this->field[2] == this->field[5] && this->field[5] == this->field[8])))    // -*-  --*
          {                                                                               // *--  --*
              if (this->field[2] == 1){
                  flag = 1;
              } else {
                  flag = -1;
              }
          }
    else if (this->field[6] != 0 && this->field[6] == this->field[7] && this->field[7] == this->field[8]) // ---
    {                                                                                                     // ---
        if (this->field[6] == 1){                                                                         // ***
            flag = 1;
        } else {
            flag = -1;
        }
    }
    else if (this->field[0] !=0 && this->field[1] !=0 && this->field[2] !=0 &&
             this->field[3] !=0 && this->field[4] !=0 && this->field[5] !=0 &&
             this->field[6] !=0 && this->field[7] !=0 && this->field[8] !=0)
    {
        flag = 2;
    }
return flag;
}

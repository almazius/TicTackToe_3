#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    field_buttons = new QPushButton*();
    for(int i=0; i<9; i++)
    {
        field_buttons[i] = new QPushButton(this);
    }
    clear_field_button = new QPushButton(this);
    this->step_by = new QLabel(this);
    this->menu_label = new QLabel(this);
    this->step_by_static_label = new QLabel(this);
    showFieldButtons();
    game = new Game();

    connect(field_buttons[0],SIGNAL(clicked()), this, SLOT(clicked_on_p1()));
    connect(field_buttons[1],SIGNAL(clicked()), this, SLOT(clicked_on_p2()));
    connect(field_buttons[2],SIGNAL(clicked()), this, SLOT(clicked_on_p3()));
    connect(field_buttons[3],SIGNAL(clicked()), this, SLOT(clicked_on_p4()));
    connect(field_buttons[4],SIGNAL(clicked()), this, SLOT(clicked_on_p5()));
    connect(field_buttons[5],SIGNAL(clicked()), this, SLOT(clicked_on_p6()));
    connect(field_buttons[6],SIGNAL(clicked()), this, SLOT(clicked_on_p7()));
    connect(field_buttons[7],SIGNAL(clicked()), this, SLOT(clicked_on_p8()));
    connect(field_buttons[8],SIGNAL(clicked()), this, SLOT(clicked_on_p9()));

    connect(clear_field_button,SIGNAL(clicked()), this, SLOT(clicked_on_new_game()));

    connect(this, &MainWindow::clickedOnFieldSignal, this, &MainWindow::clickOnField);
}

void MainWindow::clicked_on_new_game()
{
    for(int i=0; i<9; i++)
    {
        field_buttons[i]->setText("");
    }
    game->newGame();
}

void MainWindow::clickOnField(int num)
{
    if(field_buttons[num]->text().isEmpty())
    {
        int step = game->getStep();

        step_by->setAlignment(Qt::AlignCenter);
        step_by->setFont(QFont("Times", 15,QFont::Bold));
        if(step<0) {

            step_by->setText("X");
            step_by->setAlignment(Qt::AlignCenter);
            step_by->setStyleSheet("background: rgb(222,222,222);"
                                   "color: rgb(255,0,0);");

        } else {
            step_by->setText("0");
            step_by->setStyleSheet("background: rgb(222,222,222);"
                                   "color: rgb(50,255,0);");
        }

        if(step>0)
        {
            this->field_buttons[num]->setText("X");
//            this->field_buttons[num]->setAlignment(Qt::AlignCenter);
            this->field_buttons[num]->setStyleSheet("color: rgb(255,0,0);");
            this->field_buttons[num]->setFont(QFont("Times", 15,QFont::Bold));

            // css
        } else {
            this->field_buttons[num]->setText("0");
            this->field_buttons[num]->setStyleSheet("color: rgb(50,255,0);");
            this->field_buttons[num]->setFont(QFont("Times", 15,QFont::Bold));
            // css
        }
        if(game->clickOnField(num)){
            clicked_on_new_game();
            step_by->setText("X");
            step_by->setStyleSheet("background: rgb(222,222,222);"
                                   "color: rgb(255,0,0);");        }
    }
}

void MainWindow::clicked_on_p1()
{
    emit clickedOnFieldSignal(0);
}
void MainWindow::clicked_on_p2()
{
    emit clickedOnFieldSignal(1);
}
void MainWindow::clicked_on_p3()
{
    emit clickedOnFieldSignal(2);
}
void MainWindow::clicked_on_p4()
{
    emit clickedOnFieldSignal(3);
}
void MainWindow::clicked_on_p5()
{
    emit clickedOnFieldSignal(4);
}
void MainWindow::clicked_on_p6()
{
    emit clickedOnFieldSignal(5);
}
void MainWindow::clicked_on_p7()
{
    emit clickedOnFieldSignal(6);
}
void MainWindow::clicked_on_p8()
{
    emit clickedOnFieldSignal(7);
}
void MainWindow::clicked_on_p9()
{
    emit clickedOnFieldSignal(8);

}

MainWindow::~MainWindow()
{
    delete[] field_buttons;
    // ...
    delete game;
    delete clear_field_button;
    delete step_by_static_label;
    delete step_by;
    delete menu_label;
    delete ui;
}

void MainWindow::showFieldButtons()
{
    int firstX=100;
    int firstY=100;
    for(int i=0;i<3;i++){
        firstX=100;
        for(int j=0;j<3;j++)
        {
            field_buttons[(3*i)+j]->setGeometry(firstX, firstY, 90, 90);
//            field_buttons[(3*i)+j]->setStyleSheet("background: rgb(222,222,5);");
            firstX+=90;
        }
        firstY+=90;
    }
    clear_field_button->setGeometry(550, 240, 90, 35);
    clear_field_button->setText("New Game");


    menu_label->setGeometry(547, 100, 90, 35);
    menu_label->setText("Menu");
    menu_label->setAlignment(Qt::AlignCenter);
    menu_label->setFont(QFont("Times", 15,QFont::Bold));
    menu_label->setStyleSheet("font-size: 15;");

    step_by_static_label->setGeometry(574, 140, 45,35);
    step_by_static_label->setText("Step by:");

    step_by->setGeometry(576, 170, 35, 35);
    step_by->setText("X");
    step_by->setAlignment(Qt::AlignCenter);
    step_by->setFont(QFont("Times", 15,QFont::Bold));
    step_by->setStyleSheet("background: rgb(222,222,222);"
                           "color: rgb(255,0,0);");

}

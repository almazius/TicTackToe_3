#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QLabel>
#include "game.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void clicked_on_p1();
    void clicked_on_p2();
    void clicked_on_p3();
    void clicked_on_p4();
    void clicked_on_p5();
    void clicked_on_p6();
    void clicked_on_p7();
    void clicked_on_p8();
    void clicked_on_p9();

    void clicked_on_new_game();

    void clickOnField(int num);



signals:
    void clickedOnFieldSignal(int num);

private:
    Ui::MainWindow *ui;
    QPushButton **field_buttons;
    Game *game;
    void showFieldButtons();
    QPushButton *clear_field_button;
    QLabel *step_by;
    QLabel *menu_label;
    QLabel *step_by_static_label;
};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>

using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void kliknieto(int x, int y); //funkcja wywoływana gdy kliknięto jakiś button
    void wyswietl (); //wyświetla zawartość tablicy na planszy
    int is_this_win (); //sprawdza czy gracz wygrał i czy gra się nie skończyła
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_pressed();

    void on_pushButton_11_pressed();

private:
    Ui::MainWindow *ui;
    int user, punktyX, punktyY; //id użytkownika, ilość punktów gracza X, ilość p gracza Y
    QString tab[3][3]; //tablica postawionych przez graczy znaków
};

#endif // MAINWINDOW_H

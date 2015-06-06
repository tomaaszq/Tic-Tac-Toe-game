#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    user = 0;
    punktyX = 0;
    punktyY = 0;

    // pętla czyści plansze
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            tab[i][j]=" ";
        }
    }
    ui->setupUi(this);
    ui->groupBox->setHidden(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::kliknieto(int x, int y) // x,y - współrzędne klikniętego pola
{
    int winner;
    if(tab[x][y]==" ")
    {
    if(user==0)
    {
        tab[x][y]="X";
        user=1;
    }
    else
    {
        tab[x][y]="O";
        user=0;
    }
    }
    wyswietl();

    winner = is_this_win();
    if(winner!=0)
    {
        if(winner==1)
        {
            punktyX++;
            ui->textBrowser->setText("         Wygrał gracz X! \n     gracz X:" + (QString::number(punktyX)) + "     gracz O:" + (QString::number(punktyY)));
        }
        if(winner==2)
        {
            punktyY++;
            ui->textBrowser->setText("         Wygrał gracz O! \n     gracz X:" + (QString::number(punktyX)) + "     gracz O:" + (QString::number(punktyY)));
        }
        if(winner==3)
        {

            ui->textBrowser->setText("                REMIS!");
        }
        ui->groupBox->setHidden(false);
    }
}
void MainWindow::wyswietl()
{
    ui->pushButton->setText(tab[0][0]);
    ui->pushButton_2->setText(tab[0][1]);
    ui->pushButton_3->setText(tab[0][2]);
    ui->pushButton_4->setText(tab[1][0]);
    ui->pushButton_5->setText(tab[1][1]);
    ui->pushButton_6->setText(tab[1][2]);
    ui->pushButton_7->setText(tab[2][0]);
    ui->pushButton_8->setText(tab[2][1]);
    ui->pushButton_9->setText(tab[2][2]);
}
int MainWindow::is_this_win() //funckja zwraca: 0-gdy nikt nie wygrał,1-wygrał X,2-wygrał Y,3-remis
{
    QString zmienna;
    bool isA,isB,isA1,isB1,win;
    for(int i=0;i<3;i++)  //sprawdzenie wygranej w kolumnach i wierszach
    {
        zmienna=tab[i][0]+tab[i][1]+tab[i][2];
        isA=zmienna=="XXX";
        isB=zmienna=="OOO";
        zmienna=tab[0][i]+tab[1][i]+tab[2][i];
        isA1=zmienna=="XXX";
        isB1=zmienna=="OOO";
        win=isA||isB||isA1||isB1;
        if(win)
        {
            break;
        }
    }
    if (!win) //sprawdzenie wygranej na przekątnych
    {
        zmienna=tab[0][0]+tab[1][1]+tab[2][2];
        isA=zmienna=="XXX";
        isB=zmienna=="OOO";
        zmienna=tab[0][2]+tab[1][1]+tab[2][0];
        isA1=zmienna=="XXX";
        isB1=zmienna=="OOO";
        win=isA||isB||isA1||isB1;
    }
    if(win)
    {
        if(isA||isA1)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(tab[i][j]==" ")
                {
                    return 0;
                }
            }
        }
        return 3;
    }
}

void MainWindow::on_pushButton_clicked()
{
   kliknieto(0,0);
}

void MainWindow::on_pushButton_2_clicked()
{
    kliknieto(0,1);
}

void MainWindow::on_pushButton_3_clicked()
{
    kliknieto(0,2);
}

void MainWindow::on_pushButton_4_clicked()
{
    kliknieto(1,0);
}

void MainWindow::on_pushButton_5_clicked()
{
    kliknieto(1,1);
}

void MainWindow::on_pushButton_6_clicked()
{
    kliknieto(1,2);
}

void MainWindow::on_pushButton_7_clicked()
{
    kliknieto(2,0);
}

void MainWindow::on_pushButton_8_clicked()
{
    kliknieto(2,1);
}

void MainWindow::on_pushButton_9_clicked()
{
    kliknieto(2,2);
}


void MainWindow::on_pushButton_10_pressed() //zamyka aplikację, gdy gracz tego żąda
{
    QApplication::quit();
}

void MainWindow::on_pushButton_11_pressed() //czyści plansze do nowej gry
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            tab[i][j]=" ";
        }
    }
    ui->groupBox->setHidden(true);
    wyswietl();
}

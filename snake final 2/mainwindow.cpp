#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "players.h"
#include <stdio.h>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <random>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include <windows.h>



players p1 = players("m",0);
players p2 = players("r",0);
players p3 =  players("l",0);
players p4 =  players("s",0);
deque<players> pList;       //List of Players
int pTurn;                  //Variable containing player turn


//Default Setup for Ui
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_pressed()
{
    pList.clear();                  //Deque is loaded
    pList.push_back(p1);
    pList.push_back(p2);
    pList.push_back(p3);
    pList.push_back(p4);
    pTurn = 0;                      //pTurn = 0 (player 1's turn)

}



//start button
void MainWindow::on_pushButton_clicked()
{
    srand((int)time(0));                //increases randomness of the roll
    int roll =  (rand()% 6) + 1;        //dice roll
    ui->turnView->display(pTurn+1);     //display's player turn
    ui->diceView->display(roll);
    Sleep(500);                         // slight delay to view 6

    int pos = pList[pTurn].getPosition();       //retrieves player's starting position (0)

        if (pos == 0 & roll != 6)       //When player is at start and waiting for a 6
        {

            pList[pTurn].setPosition(pos);
        }
        else if (pos == 26 & roll != 6)     //When player is at the first black hole and waiting for a 6
        {
            pList[pTurn].setPosition(pos);

        }
        else if (pos == 86 & roll != 6)     //When player is at second black hole and waiting for a 6
        {
            pList[pTurn].setPosition(pos);

        }
        else                                //Any other move of the player
        {
            pList[pTurn].updatePosition(roll);
        }


    pos = pList[pTurn].getPosition();       //new position after the roll
    int xPos;
    int yPos;
    if (((pos/10)%2 == 0 || (((pos/10)%2 == 1) && (pos%10 == 0)))){//formula for finding the x position in the grid using the position variable
    xPos = 40 + ((pos%10)-1)*70;
    } else {
    xPos = 670 - ((pos%10)-1)*70;
    }
    yPos = 770 - int(((pos-1)/10))*50;// formula for finding y position in the grid using the the game position variable
    switch(pTurn){
    case 0://each player has an offset of 10 pixels to the right of each other, so you can tell what happens if they stack
        ui->player1->move(xPos,yPos);
        break;
    case 1:
        ui->player2->move(xPos-10,yPos);
        break;
    case 2:
        ui->player3->move(xPos-20,yPos);
        break;
    case 3:
        ui->player4->move(xPos-30,yPos);
        break;
    }
    if(pos > 99){           //game has a winner
        ui->lcdNumber->display(pTurn+1);
    }
    pTurn++;
    if(pTurn>3){            //Keeping track of the turns
        pTurn = 0;
    }
}



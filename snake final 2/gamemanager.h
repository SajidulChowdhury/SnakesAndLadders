#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <deque>
#include <iostream>
#include <string>
#include <players.h>
class gamemanager{
private:
    deque<players> pList;
    int pTurn;
    players p1 = players("h",0,0);
    players p2 = players("a",0,0);
    players p3 =  players("m",0,0);
    players p4 =  players("d",0,0);
    int winner;
public:
    // Start the game
    void init(){
       pList.clear();
       pList.push_back(p1);
       pList.push_back(p2);
       pList.push_back(p3);
       pList.push_back(p4);
       for (int i = 0; i < 4; i++){
           pList[i].setPosition(0);
       }
       winner = 0;
       pTurn = 0;
    }
    // Check to see if the game is over
    bool gameOver(){
        for(int i = 0; i < 4; i++){
            if (pList[i].getPosition() >= 100){
                this->winner = i;
                return true;
            }
        }
        return false;
    }
    // Get the winner
    int getwinner(){
        return this->winner;
    }
    // This will update the Player's turn in the game and the display
    void updatePTurn(){
        this->pTurn++;
        if (pTurn>3){
            this->pTurn = 0;
        }
    }
    // This is an accessor method for Player turn
    int getPturn(){
        return this->pTurn;
    }
    //this is an accessor method for Player deque
    deque<players> getpList(){
        return this->pList;
    }
};

#endif // GAMEMANAGER_H

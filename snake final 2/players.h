#ifndef PLAYERS_H
#define PLAYERS_H
#include <deque>
#include <iostream>
#include <string>
using namespace std;
class players {
private:
    string name;
    int position;
public:

    players() {
        name = "";
        position = 0;
    }

    players(string n, int p) {
        name = n;
        position = p;
    }

    //Current Position function
    int getPosition() const {
        return position;
    }
    //Unchanged Position function
    void setPosition(int x){
        this->position = x;
    }

    //Dice Roll
    int rollDice() {
        return rand() % 6 + 1;
    }

    //Update of position when not at 0 or black hole
    int updatePosition(int a) {
            position += a;
        switch (position) {
            case 22:        //Ladders
                position = 79;
                break;
            case 16:
                position = 56;
                break;
            case 53:
                position = 93;
                break;
            case 80:        //Snakes
                position = 41;
                break;
            case 84:
                position = 24;
                break;
            case 72:
                position = 9;
                break;

}
        return position;
}
};



#endif // PLAYERS_H

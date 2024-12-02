#pragma once
#include <iostream>
#include "Board.h"
using namespace std;

class Player : public Board {
    public:
        Player();// Default constructor.
        Player(string, string);// Constructor.
        bool hasWon(string);// Checks if they have won.
        int menu(string);// Player choice thing. I'm not programming a computer right now, I know how difficult that would be. It would literaly double my work.
        void display();// Runs the Board class's display function.
        void play(int, string, bool);// Runs the Board class's play function.

    //private:
        string mark1, mark2;// The mark that is put on the board by the players.
};

Player::Player() {
    mark1 = "1";
    mark2 = "2";
}

Player::Player(string m, string n) {
    mark1 = m;
    mark2 = n;
}

bool Player::hasWon(string mark) {
    Board::format();
    /*string mark;// Which mark is being checked, and therefore which player the program is checking the win condition for.
    if (player == 1) {
        mark = mark1;
    } else {
        mark = mark2;
    }*/
    bool end = false;// Whether a win condition has been found. I like having a variable called end, so thats why it's called that.
    bool going = true;// Swaps to false if the entire board has been checked.
    int placex = 0, placey = 0;// Where the program is checking, or at least the first spot.

    while (end == false && going) {// Checks for horizontal win conditions
        //cout << Board::game[placey][placex];
        //cout << Board::game[0][0];
        if (Board::game[placey][placex] == mark && Board::game[placey][placex + 1] == mark && Board::game[placey][placex + 2] == mark && Board::game[placey][placex + 3] == mark) {
            return true;
        } else {
            if (placex > 1) {
                placex = 0;
                placey++;
            } else {
                placex++;
            }
        }

        if (placey >= 5) {
            going = false;
            //cout << "debug";
        }
    }

    placex = 0;// Resets these variables for the next iteration.
    placey = 0;
    going = true;

    while (end == false && going) {// Checks for vertical win conditions
        //cout << Board::game[placey][placex];
        //cout << Board::game[0][0];
        if (Board::game1[placey][placex] == mark && Board::game1[placey][placex + 1] == mark && Board::game1[placey][placex + 2] == mark && Board::game1[placey][placex + 3] == mark) {
            return true;
        } else {
            if (placex > 1) {
                placex = 0;
                placey++;
            } else {
                placex++;
            }
        }

        if (placey >= 5) {
            going = false;
            //cout << "debug";
        }
    }

    placex = 0;// Resets these variables for the next iteration.
    placey = 0;
    going = true;

    while (end == false && going) {// Checks for diagonal win conditions.
        if (Board::game[placey][placex] == mark && Board::game[placey + 1][placex + 1] == mark && Board::game[placey + 2][placex + 2] == mark && Board::game[placey + 3][placex + 3] == mark) {
            //cout << "Works";// debug
            return true;
        } else {
            if (placex >= 2) {
                placex = 0;
                placey++;
            } else {
                placex++;
            }
        }

        if (placey >= 2) {
            going = false;
            //cout << "debug";
        }
    }

    placex = 5;// Resets these variables for the next iteration.
    placey = 0;
    going = true;

    while (end == false && going) {// Checks for diagonal win conditions the other way.
        if (Board::game[placey][placex] == mark && Board::game[placey + 1][placex - 1] == mark && Board::game[placey + 2][placex - 2] == mark && Board::game[placey + 3][placex - 3] == mark) {
            return true;
        } else {
            if (placex <= 3) {
                placex = 5;
                placey++;
            } else {
                placex--;
            }
        }

        if (placey >= 2) {
            going = false;
            //cout << "debug";
        }
    }

    return end;
}

int Player::menu(string mark) {
    int end = 0;
    bool ender = true;
    while(ender) {
        cout << endl << "Select which column to play in: ";
        cin >> end;
        end--;
        if(end < 0 || end > 5) {
            cout << "Not a valid number. Try again." << endl;
        }else if (Board::play(end, mark, false)) {
            cout << "Not a valid input. Try again." << endl;
        } else {
            ender = false;
        }
    }
    return end;
}

void Player::display() {
    Board::display();
}

void Player::play(int q, string s, bool b) {
    Board::play(q, s, b);
}

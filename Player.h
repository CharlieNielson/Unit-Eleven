#pragma once
#include <iostream>
#include "Board.h"
using namespace std;

class Player : public Board {
    public:
        Player();// Default constructor.
        Player(string, string);// Regular constructor.
        bool hasWon(int);// Checks if they have won.
        int menu(string, int);// Player choice thing. I'm not programming a computer right now, I know how difficult that would be. It would literaly double my work.

    private:
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

bool Player::hasWon(int player) {
    Board::format();
    string mark;// Which mark is being checked, and therefore which player the program is checking the win condition for.
    if (player == 1) {
        mark = mark1;
    } else {
        mark = mark2;
    }
    bool end = false;// Whether a win condition has been found. I like having a variable called end, so thats why it's called that.
    bool going = true;// Swaps to false if the entire board has been checked.
    int placex = 0, placey = 0;// Where the program is checking, or at least the first spot.

    while (end == false && going) {// Checks for horizontal win conditions
        if (game[placey][placex] == mark && game[placey][placex + 1] == mark && game[placey][placex + 2] == mark && game[placey][placex + 3] == mark) {
            end = true;
        } else {
            if (placex >= 2) {
                placex = 0;
                placey++;
            } else {
                placex++;
            }
        }

        if (placey >= 5) {
            going = false;
        }
    }

    placex = 0;// Resets these variables for the next iteration.
    placey = 0;
    going = true;

    while (end == false && going) {// Checks for a vertical win condition by swapping the x and y variables.
        if (game[placex][placey] == mark && game[placex][placey + 1] == mark && game[placex][placey + 2] == mark && game[placex][placey + 3] == mark) {
            end = true;
        } else{
            if (placey >= 2) {
                placey = 0;
                placex++;
            } else {
                placey++;
            }
        }

        if (placex >= 5) {
            going = false;
        }
    }

    placex = 0;// Resets these variables for the next iteration.
    placey = 0;
    going = true;

    while (end == false && going) {// Checks for diagonal win conditions
        if (game[placey][placex] == mark && game[placey + 1][placex + 1] == mark && game[placey + 2][placex + 2] == mark && game[placey + 3][placex + 3] == mark) {
            end = true;
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
        }
    }

    placex = 0;// Resets these variables for the next iteration.
    placey = 0;
    going = true;

    while (end == false && going) {// Checks for a diagonal win condition the other way by swapping the x and y variables.
        if (game[placex][placey] == mark && game[placex + 1][placey + 1] == mark && game[placex + 2][placey + 2] == mark && game[placex + 3][placey + 3] == mark) {
            end = true;
        } else{
            if (placey >= 2) {
                placey = 0;
                placex++;
            } else {
                placey++;
            }
        }

        if (placex >= 2) {
            going = false;
        }
    }

    return end;
}

#pragma once
#include <iostream>
using namespace std;

class Board {
    public:
        Board();// Constructer.
        void display();// Displays the board.
        void format();// Updates game1 to match game.

    protected:
        // The first number is the y, with the bottom row being 0.
        // The second is the column, with the leftmost one being 0.
        string game[6][6];// The board.
        string game1[6][6];// Alternate formatting of the board for ease of checking the win condition.

};

Board::Board() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            game[i][j] = "_";
        }
    }

    //game[3][2] = "O";// Debugger

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            game1[j][i] = "_";
        }
    }
}

void Board::display() {
    cout << "The board as it stands: " << endl;
    for (int i = 5; i >= 0; i--) {
        cout << "|";
        for (int j = 0; j < 6; j++) {
            cout << game[i][j] << "|";
        }
        cout << endl;
    }
}

void Board::format() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            game1[i][j] = game[j][i];
        }
    }
}

#pragma once
#include <iostream>
using namespace std;

class Board {
    public:
        Board();// Constructer.
        void display();// Displays the board.
        void format();// Updates game1 to match game.
        bool play(int, string, bool);// Places the mark in the board.

    protected:
        // The first number is the y, with the bottom row being 0.
        // The second is the x, with the leftmost column being 0.
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
    //cout << "The board as it stands: " << endl;
    for (int i = 5; i >= 0; i--) {
        cout << "|";
        for (int j = 0; j < 6; j++) {
            cout << game[i][j] << "|";
        }
        cout << endl;
    }

    for (int i = 1; i < 7; i++) {
        cout << "/" << i;
    }
    cout << "/" << endl;
    //cout << "debug";
}

void Board::format() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            game1[i][j] = game[j][i];
        }
    }
}

bool Board::play(int column, string mark, bool change) {
    bool end = true;
    bool ender = false;
    int row = 0;
    while (ender == false) {
        if (game[row][column] == "_") {
            if (change) {
                game[row][column] = mark;
            }
            ender = true;
            end = false;
        } else {
            row++;
            if (row > 5) {
                cout << "Sorry, column was full. Try again." << endl;
                end = true;
                ender = true;
            }
        }
    }
    return end;
}

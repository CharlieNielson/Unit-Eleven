#include <iostream>
#include "Board.h"
#include "Player.h"
using namespace std;

int main() {
    //cout << "debug";

    //Board b;
    Player p("X", "O");

    //system("clear");
    //b.display();

    bool gameEnd = false;
    string winner = "literaly nobody... How have you tied?";

    while (gameEnd == false) {

        cout << "Connect Four!" << endl;
        p.display();
        //cout << gameEnd << endl;//debug
        cout << "Player one's turn." << endl;
        p.play(p.menu(p.mark1), p.mark1, true);
        gameEnd = p.hasWon(p.mark1);
        if (p.hasWon(p.mark1)) {
            winner = "Player One.";
        }
        system("clear");

        if (gameEnd == false) {
            cout << "Connect Four!" << endl;
            p.display();
            //cout << gameEnd << endl;//debug
            cout << "Player two's turn." << endl;
            p.play(p.menu(p.mark2), p.mark2, true);
            gameEnd = p.hasWon(p.mark2);
            if (p.hasWon(p.mark2)) {
                winner = "Player Two.";
            }
            gameEnd = p.antiSoftLock(gameEnd);
            system("clear");
        }
    }
    
    cout << "Game End." << endl;
    p.display();
    cout << "Game over! Winner is " << winner << endl;


    return 17;
}

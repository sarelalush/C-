#include <iostream>
#include "BoardGame.h"

using namespace std;


int main() {

    colorDisk player ;
    int dice1 = 0, dice2 = 0, diceDouble = 0 ,from = 0, to = 0 , moveNumber = 0 ,seed = 0;
    bool noMoreMoves = true , isWinner = false;
    cout<< "Enter seed"<<endl;
    cin >> seed;
    if(cin.fail()){
        cout <<"Missing user input - quiting game."<<endl;
        return 0;
    }

    BoardGame b(seed);
    string players[2] = {"Black","White"};
    if (b.whoStart() == Black)
        player = Black;
    else
        player = White;
    cout <<players[player]<<" plays first."<<endl;
    b.printBoard(player);
    while(!isWinner) {
        dice1 = b.getRndNumber();
        dice2 = b.getRndNumber();
        cout << players[player] << " rolls "<<dice1 << "-" << dice2 << "."<<endl;
        if(dice1 == dice2) {
            moveNumber = 4;
            diceDouble = dice1;
        }
        else
            moveNumber = 2;

        for (int i = 0; i < moveNumber; ++i) {
            noMoreMoves = b.checkForMoreMoves(dice1 , dice2 , player);
            if(b.checkWinner(player))
                break;
            if(!noMoreMoves ){
                cout << "No possible move for Black"<<endl;
                break;
            }

            do{
                cout <<"Enter "<<players[player]<<" move: "<<endl;
                cin >> from >> to;
                if(cin.fail()){
                    cout <<"Missing user input - quiting game."<<endl;
                    return 0;
                }

            }while(noMoreMoves && !b.checkValidMove(from,to,player,dice1,dice2));

            b.moveDisk(from,to,dice1,dice2,player);
            if(dice1 == 0 && dice2 == 0)
                dice1 = dice2 = diceDouble;
        }
        if(b.checkWinner(player)){
            isWinner = true;
        }
        else {
            player = player == Black ? White : Black;
            b.printBoard(player);
        }

    }
    cout << players[player] <<" player wins!"<<endl;
    return 1;
}

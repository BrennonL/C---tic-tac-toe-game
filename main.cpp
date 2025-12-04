#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

#include "board.h"

char GetInputs(char player){
    char choice;
    bool correctValue = true;
    do{

        cout << "It is " << player << "'s turn, what do you pick?" << endl; 
        cin >> choice;

        set<char> correctChoices = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'q'};
        if(correctChoices.contains(choice)){
            correctValue = true;
        }
        else{
            correctValue = false;
        }
        if (correctValue == false){
            cout << choice << " is not a correct value." << endl;
        }

    }while(correctValue = false);

    return choice;
};

void DoUpdates(char player, char choice, Board* myBoard) {
    myBoard->ChangeValue(choice, player);
}

void DoOutputs(Board* myBoard) {
    myBoard->CreateBoard();
}


int main(){
    bool win = false;
    
    Board The_board;

    Board* myBoard = new Board();
    //The_board.CreateBoard();
    myBoard->CreateBoard();

    char player = 'x';
    do{
        char choice = GetInputs(player);
        DoUpdates(player, choice, myBoard);
        DoOutputs(myBoard);


        // This allows the user to quit during the game if they want to
        if(choice == 'q'){
            win = true;
        }

        //This if/else statement will simply switch the turns of the players
        if (player == 'x'){
            player = 'o';
        }
        else{
            player = 'x';
        }
        //win = The_board.DetermineWinner();        
        win = myBoard->DetermineWinner();
    }while(win == false);

    delete myBoard;

    cout << "Congratulations! You won!" << endl;
    return 0;
};
#include <iostream>
#include "board.h"
using namespace std;

/// @brief This function will ask the user what area they want to pick from
/// @param player 
/// @return choice variable
char GetInputs(char player){
    char choice;
    cout << "It is " << player << "'s turn, what do you pick?" << endl; 
    cin >> choice;
    return choice;
};



/// @brief This will update the board list with either the char 'x' or 'o' using the ChangeValue() function 
/// @brief from the board.h 
/// @param player 
/// @param choice 
/// @param The_board 
/// @param operation 
void DoUpdates(char player, char choice, Board& The_board, void (Board::*operation)(char, char)){
    (The_board.*operation)(choice, player);
};



/// @brief This will display the board using the CreateBoard() from board.h
/// @param The_board 
/// @param operation 
void DoOutputs(Board& The_board, void (Board::*operation)()){
    (The_board.*operation)();
};



/// @brief This is my main function
/// @return 
int main(){
    bool win = false;
    
    Board The_board;
    The_board.CreateBoard();

    char player = 'x';
    do{
        char choice = GetInputs(player);
        DoUpdates(player, choice, The_board, Board::ChangeValue);
        DoOutputs(The_board, Board::CreateBoard);

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
        win = The_board.DetermineWinner();        
    }while(win == false);


    cout << "Congratulations player" << player << "! You won!" << endl;

    return 0;
};




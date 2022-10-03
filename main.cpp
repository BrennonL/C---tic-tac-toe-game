#include <iostream>
#include "board.h"
using namespace std;

void DoUpdatesPointer(char player, char choice, Board* The_board, void (Board::*operation)(char, char)){
    (The_board->*operation)(choice, player);
};


/// @brief This will display the board using the CreateBoard() from board.h
/// @param The_board 
/// @param operation 
void DoOutputsPointer(Board* The_board, void (Board::*operation)()){
    (The_board->*operation)();
};





/// @brief This function will ask the user what area they want to pick from
/// @param player 
/// @return choice variable
char GetInputs(char player){
    char choice;
    bool correctValue = true;
    do{

        // Here the program will ask the user for their choice where they want to mark their symbol and assigns that answer to the
        //variable choice.
        cout << "It is " << player << "'s turn, what do you pick?" << endl; 
        cin >> choice;

        // These if and else statements verrify that the user put in a number rather than a character or letter. If they didn't put a 
        //number then it will run through the loop again asking the user for a number.
        if(choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '5' || choice == '6' || choice == '7' ||
        choice == '8' || choice == '9' || choice == 'q'){
            correctValue = true;
        }
        else{
            correctValue = false;
        }
        if (correctValue == false){
            cout << choice << "is not a correct value." << endl;
        }

    }while(correctValue = false);

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

    Board * The_board01 = new Board();
    //The_board.CreateBoard();
    The_board01->CreateBoard();

    char player = 'x';
    do{
        char choice = GetInputs(player);
        //DoUpdates(player, choice, The_board, Board::ChangeValue);
        //DoOutputs(The_board, Board::CreateBoard);
        DoUpdatesPointer(player, choice, The_board01, Board::ChangeValue);
        DoOutputsPointer(The_board01, Board::CreateBoard);

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
        win = The_board01->DetermineWinner();
    }while(win == false);

    delete The_board01;

    cout << "Congratulations! You won!" << endl;
    return 0;
};




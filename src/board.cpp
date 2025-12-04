#include <iostream>
using namespace std;

#include "board.h"

Board::Board() :board{
            {'1','|', '2', '|', '3'},
            {'-', '-', '-', '-', '-'},
            {'4','|', '5', '|', '6'},
            {'-', '-', '-', '-', '-'},
            {'7','|', '8', '|', '9'}
        }{}

void Board::CreateBoard() {
    for(int i = 0; i < 5; i ++){
        for(int j = 0; j < 5; j ++){
            cout << board[i][j];
        }
        cout << endl;
    }
}

void Board::ChangeValue(char choice, char character) {
    for (int i = 0; i < 5; i ++){
        for (int j = 0; j < 5; j ++){
            if (board[i][j] == choice){
                board[i][j] = character; 
            }
        }
    }
}

bool Board::DetermineWinner() {
    bool winner = false;
    // If any of the rows are all the same then  return that the winner is true
    if(board[0][0] == board[0][2] && board[0][4] == board[0][2]){
        return winner = true;   
    }
    else if (board[2][0] == board[2][2] && board[2][4] == board[2][2])
    {
        return winner = true;   
    }
    else if (board[4][0] == board[4][2] && board[4][4] == board[4][2])
    {
        return winner = true;
    }
    // If any of the columns are all the same then return that the winner is true
    else if (board[0][0] == board[2][0] && board[4][0] == board[2][0])
    {
        return winner = true;
    }
    else if (board[0][2] == board[2][2] && board[4][2] == board[2][2])
    {
        return winner = true;
    }
    else if (board[0][4] == board[2][4] && board[4][4] == board[2][4])
    {
        return winner = true;
    }
    // If any of the diagonals are all the same return that the winner is true
    else if (board[0][0] == board[2][2] && board[4][4] == board[2][2])
    {
        return winner = true;
    }
    else if (board[0][4] == board[2][2] && board[4][0] == board[2][2])
    {
        return winner = true;
    }
    else{
        return winner = false;
    }
}
#pragma use once

#include <iostream>
using namespace std;

class Board{
    private:
        char board[5][5];

    public:
        Board();
        void CreateBoard();
        void ChangeValue(char choice, char player);
        bool DetermineWinner();
};
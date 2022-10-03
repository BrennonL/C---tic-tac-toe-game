#include <iostream>
using namespace std;

class Board{
    private:
        char board[5][5] = {
            {'1','|', '2', '|', '3'},
            {'-', '-', '-', '-', '-'},
            {'4','|', '5', '|', '6'},
            {'-', '-', '-', '-', '-'},
            {'7','|', '8', '|', '9'}
        };

        // string board[5][5] = {
        //     {"1","|", "2", "|", "3"},
        //     {"-", "-", "-", "-", "-"},
        //     {"4","|", "5", "|", "6"},
        //     {"-", "-", "-", "-", "-"},
        //     {"7","|", "8", "|", "9"}
        // };


    public:
        /// @brief This will loop through the board array and display each item. Each time it gets to 
        /// @brief the end on one of the arrays in the array will start a new line
        void CreateBoard(){
            // Do I need to pass the array into the function?
            for(int i = 0; i < 5; i ++){
                for(int j = 0; j < 5; j ++){
                    cout << board[i][j];
                }
                cout << endl;
            }
        };

        /// @brief This function will take the input by the player and put the characters name in the place of the number
        /// @param choice 
        /// @param player 
        void ChangeValue(char choice, char player){
            for (int i = 0; i < 5; i ++){
                for (int j = 0; j < 5; j ++){
                    if (board[i][j] == choice){
                        board[i][j] = player; 
                    }
                }
            }
        }

        /// @brief This function will see if any of the colums, rows, or diagonals match symbols and if they do then it returns the winning condition
        /// @param winner 
        /// @return winner bool variable
        bool DetermineWinner(){
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
};
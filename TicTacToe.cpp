#include <iostream>
#include <cstdlib>
#include <ctime>
#include "TicTacToe.h"

using namespace std;

TicTacToe::TicTacToe(){
    srand(time(NULL));
    // Initialize Board
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = '-';
        }
    }
    // Initialize currentPlayey
    this->currentPlayer = 'X';
    // Initialize winner to nobody
    this->winner = '-';
}
void TicTacToe::print(){
    for(int i = 0; i < 3; i++){
        cout << "  " << i+1;
    }
    cout << endl;
    for(int i = 0; i < 3; i++){
        cout << i+1 << "  ";
        for(int j = 0; j < 3; j++){
            cout << this->board[i][j] << "  ";
        }
        cout << endl;
    }
}
void TicTacToe::makeMove(int row, int col){
    if(!this->isValidMove(row, col)) return;
    this->board[row][col] = this->currentPlayer;
    if(this->currentPlayer == 'X'){
        this->currentPlayer = 'O';
    }else{
        this->currentPlayer = 'X';
    }
}
bool TicTacToe::isValidMove(int row, int col){
    if(this->board[row][col] == '-' && row < 3 && col < 3){
        return true;
    }else{
        return false;
    }
}
char TicTacToe::getCurrentPlayer(){
    return this->currentPlayer;
}
char TicTacToe::getWinner(){
    this->isDone();
    return this->winner;
}
/* isDone sets the winner as it goes through if the game is indeed done - less decoupling but easier for me to type
 * UPDATE: Lmao when I'm worried about how much I have to type, then voluntarrily
 *  write a neural network when irl a simple "rand() % 8"ish would have done
 */
bool TicTacToe::isDone(){
    // Check Horizontal conditions
    
    for(int i = 0; i < 3; i++){
        if(this->board[i][1] == this->board[i][2] && this->board[i][1] == this->board[i][0]){
            if(this->board[i][1] == 'X' || this->board[i][1] == 'O'){
                this->winner = this->board[i][1];
                return true;
            }
        }
    }

    // Check Vertical Win conditionals
    for(int i = 0; i < 3; i++){
        if(this->board[0][i] == this->board[1][i] && this->board[0][i] == this->board[2][i]){
            if(this->board[0][i] == 'X' || this->board[0][i] == 'O'){
                this->winner = this->board[0][i];
                return true;
            }
        }
    }

    // Check Diagonal win conditions
    if(this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2]){
        if(this->board[0][0] == 'X' || this->board[0][0] == 'O'){
            this->winner = this->board[0][0];
            return true;
        }
    }
    if(this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0]){
        if(this->board[0][2] == 'X' || this->board[0][2] == 'O'){
            this->winner = this->board[0][2];
            return true;
        }
    }

    // Check board full
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(this->board[i][j] == '-'){
                this->winner = '-';
                return false;
            }
        }
    }
    this->winner = ' ';
    return true;
}
// BEGIN NEURAL NETWORK AND RANDOM ACCESSABILITY FUNCTIONS I WANTED TO IMPLEMENT
void TicTacToe::makeMove(int index){
    int row = index/3;
    int col = index%3;
    if(!this->isValidMove(row, col)) return;
    this->board[row][col] = this->currentPlayer;
    if(this->currentPlayer == 'X'){
        this->currentPlayer = 'O';
    }else{
        this->currentPlayer = 'X';
    }
}
void TicTacToe::findAvailableSpaces(){
    this->numPlaces = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(this->board[i][j] == '-'){
                this->numPlaces++;
                this->places[this->numPlaces-1] = i*3+j;
            }
        }
    }
}
int TicTacToe::getNNData(int index){
    int x = index/3;
    int y = index%3;
    if (this->board[x][y] == this->currentPlayer){
        return 1;
    }else if(this->board[x][y] == '-'){
        return 0;
    }else{
        return -1;
    }
}
void TicTacToe::makeAutoMove(){
    // Makes a random move
    // Also can be used for training the neural network
    if(!this->isDone()){
        this->findAvailableSpaces();
        int place = this->places[rand()%this->numPlaces];
        this->makeMove(place/3, place%3);
    }
}
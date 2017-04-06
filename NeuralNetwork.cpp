#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "TicTacToe.h"
#include "NeuralNetwork.h"

NN::NN(TicTacToe *game){
    srand(time(NULL));
    this->game = game;
    this->ties = 0;
    this->losses = 0;
    this->wins = 0;
    //this->game->reset();
    for(int i = 0; i < NN::INPUT_LENGTH; i++){
        for(int j = 0; j < NN::HIDDEN_LENGTH; j++){
            this->inputHidden[i][j] = static_cast<double>(((rand() % 200) - 100))/100;
        }
    }
    for(int j = 0; j < NN::HIDDEN_LENGTH; j++){
        for(int k = 0; k < NN::OUTPUT_LENGTH; k++){
            this->hiddenOutput[j][k] = static_cast<double>(((rand() % 200) - 100))/100;
        }
    }
}
void NN::setGamePointer(TicTacToe *game){
    this->game = game;
    this->finishedGame = false;
}
void NN::getCurrentBoard(){
    for(int i = 0; i < 9; i++){
        currentBoard[i] = this->game->getNNData(i);
    }
}
void NN::printCurrentBoard(){
    this->getCurrentBoard();
    for(int i = 0; i < 3; i++){
        std::cout << "  " << i+1;
    }
    std::cout << std::endl;
    for(int i = 0; i < 3; i++){
        std::cout << i+1 << "  ";
        for(int j = 0; j < 3; j++){
            std::cout << this->currentBoard[i*3+j] << "  ";
        }
        std::cout << std::endl;
    }
}
void NN::makeMove(){
    if(!this->game->isDone()){
        this->findAvailableSpaces();
        int bestMove = this->places[this->findBestMove()];
        this->game->makeMove(bestMove);
    }/*else{
        if(this->game->getWinner() == '-'){
            this->ties++;
        }else{
            this->losses++;
        }
        this->finishedGame = true;
    }
    if(this->game->isDone() && !this->finishedGame){
        if(this->game->getWinner() == '-'){
            this->ties++;
        }else{
        this->wins++;
        }
    }*/
    else{
        char winner = this->game->getWinner();
        if(winner == 'X'){
            this->losses++;
        }else if(winner = 'O'){
            this->wins++;
        }else{
            this->ties++;
        }
    }
}
int NN::findBestMove(){
    int bestMoveIndex = 0;
    double bestMoveScore = 0;
    for(int i = 0; i < this->numPlaces; i++){
        //make new board
        int newBoard[9];
        for(int j = 0; j < 9; j++){
            newBoard[j] = this->currentBoard[j];
        }
        //add move
        newBoard[this->places[i]] = 1;
        double moveScore = this->run(newBoard);
        if(moveScore >= bestMoveScore){
            bestMoveIndex = i;
            bestMoveScore = moveScore;
        }
    }
    return bestMoveIndex;
}
double NN::run(int *inputData){
    for(int j = 0; j < NN::HIDDEN_LENGTH; j++){
        this->hiddenLayer[j] = 0;
        for(int i = 0; i < NN::INPUT_LENGTH; i++){
            this->hiddenLayer[j] += this->inputHidden[i][j] * inputData[i];
        }
        this->hiddenLayer[j] = NN::sigmoid(this->hiddenLayer[j]);
    }

    for(int k = 0; k < NN::OUTPUT_LENGTH; k++){
        this->outputLayer[k] = 0;
        for(int j = 0; j < NN::HIDDEN_LENGTH; j++){
            this->outputLayer[k] += this->hiddenOutput[j][k] * this->hiddenLayer[j];
        }
        this->outputLayer[k] = NN::sigmoid(this->outputLayer[k]);
    }

    return this->outputLayer[0];
}
// Black magic
void NN::findAvailableSpaces(){
    this->numPlaces = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(this->currentBoard[i*3+j] == 0){
                this->numPlaces++;
                this->places[this->numPlaces-1] = i*3+j;
            }
        }
    }
}
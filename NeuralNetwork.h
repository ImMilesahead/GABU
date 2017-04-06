/**
 * @author Miles Smith
 */

#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include <cmath>
#include "TicTacToe.h"

/**
 * @breif NN is an AI that can make the best moves it thinks is possible from the current board state
 */
class NN{
private:
    static const int INPUT_LENGTH = 9;
    static const int HIDDEN_LENGTH = 5;
    static const int OUTPUT_LENGTH = 1;
    TicTacToe *game;
    double hiddenLayer[HIDDEN_LENGTH];
    double outputLayer[OUTPUT_LENGTH];
    double inputHidden[9][5];
    double hiddenOutput[5][1];
    int currentBoard[9];
    int places[9];
    int numPlaces;
    bool finishedGame;
    int ties;
    int losses;
    int wins;
public:
    /**
     * @brief NN Constructor initializes weight matricies and node values
     * @param TicTacToe* is a pointer to the game that the Neural Network is playing
     */
    NN(TicTacToe*);

    /**
     * @breif setGamePointer takes in a pointer to the tictactoe class that is currently being used
     * @param is a pointer to the new gzme board
     */
    void setGamePointer(TicTacToe*);

    /**
     * @breif printCurrentBoard prints the current board layout as the neuralnetwork cares about it
     */
    void printCurrentBoard();

    /**
     * @breif getCurrentBoard takes a copy of the board layout in the layout that the neural network can read
     */
    void getCurrentBoard();

    /**
     * @breif makeMove Makes a move after analyzing the favoribility of each possible move
     */
    void makeMove();

    /**
     * @breif findBestMove finds the best move in the current situation
     * @return returns the location to play
     */
    int findBestMove();

    /**
     * @brief run propagates the layout of the board through a neural network to determine the favoribility of that move
     * @return returns the calculated probability
     */
    double run(int*);

    /**
     * @breif findAvailableSpace finds all the spaces in which the NN can play this return
     */
    void findAvailableSpaces();

    int getWins() { return this->wins; }
    int getTies() { return this->ties; }
    int getLoses() { return this->losses; }

    /**
     * @breif sigmoid is the activation function we pass the output of each node through
     * @param x is the value passed in
     * @return returns the sigmoid od x
     */
    static double sigmoid(double x){
	    double e = 2.718281828459045;
        return 1/(1+std::pow(e, -x));
    }
};

#endif      // NEURAL_NETWORK_H

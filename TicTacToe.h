/**
 * @author Miles Smith
 * @breif TicTacToe class
 */

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

/**
 * @breif TicTacToe game mechanics for a tic tac toe game
 */
class TicTacToe{
public:
    char currentPlayer;
    char board[3][3];
    char winner;
    int places[9];
    int numPlaces;

    /**
     * @breif TicTacToe default constructor sets all board values to '-' sets current player to 'X' and winner to '-'
     */
    TicTacToe();
    
    /**
     * @breif print prints the board 
     */
    void print();
    
    /**
     * @breif getCurrentPlayer returns the current player
     * @return returns either 'X' or 'O'
     */
    char getCurrentPlayer();
    
    /**
     * @breif isDone determines if either player has won or if the board is full, if a player 
     * has won it sets the variable "winner" to either 'X' or 'O'. 
     * @return returns true or false if the game is over or not
     */
    bool isDone();
    
    /**
     * @breif getWinner returns either 'X' or 'O' if a player won or '-' if neither or still available moves
     * @return returns either 'X' 'O' or '-'
     */
    char getWinner();
    
    /**
     * @breif isValidMove detects if the player can play at the location provided
     * @return returns true or false if the player can play at the location
     */
    bool isValidMove(int, int);
    
    /**
     * @breif makeMove makes a move and changes the current player
     */
    void makeMove(int, int);

    
    // NN Functions
    /**
     * @breif makeMove makes a move based on a single integer representing it's position instead of 2 integers
     *      Mainly implemented so tham my Neural Network would have an easier time playing
     * @param takes in an integer representing position in the array
     */
    void makeMove(int);
    
    /**
     * @breif getNNData returns specific states of the board specifically built for the Neural Network
     * @param takes in an integer representing position similar to the makeMove function also built for the Neural Network
     */
    int getNNData(int);
    
    /**
     * @breif built in class that makes an automatic random move
     */
    void makeAutoMove();
    
    /**
     * @breif findAvailableSpaces finds the playable moves
     */
    void findAvailableSpaces();
};

#endif  // TIC_TAC_TOE_H

#ifndef DRAW_BOARD_H
#define DRAW_BOARD_H

#include <SFML/Graphics.hpp>
#include "TicTacToe.h"

class TTTGame : public TicTacToe{
private:
    sf::RenderWindow *window;
    sf::Color backgroundColor;
public:
    TTTGame(sf::RenderWindow*);
    void drawRectangle(const sf::Vector2f&, const sf::Vector2f&);
    void drawRectangle(const int&, const int&, const int&, const int&);
    void drawX(const int &x, const int &y);
    void drawO(const int &x, const int &y);
    void update();
};

#endif	// DRAW_BOARD_H

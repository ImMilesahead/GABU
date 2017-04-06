#include <SFML/Graphics.hpp>
#include <iostream>

#include "TTTGUI.h"
#include "TicTacToe.h"

TTTGame::TTTGame(sf::RenderWindow *window){
    this->window = window;
}
void TTTGame::drawRectangle(const sf::Vector2f &position, const sf::Vector2f &size){
    sf::RectangleShape rectangle(size);
    rectangle.setPosition(position);
    rectangle.setFillColor(this->backgroundColor);
    this->window->draw(rectangle);
}
void TTTGame::drawRectangle(const int &x, const int &y, const int &w, const int &h){
    this->drawRectangle(sf::Vector2f(x, y), sf::Vector2f(w, h));
}

void TTTGame::drawX(const int &x, const int &y){
    // Make X
    sf::RectangleShape line(sf::Vector2f(150, 5));
    line.setPosition(sf::Vector2f(110 + 140*x, 110 + 140*y));
    line.rotate(45);
    line.setFillColor(sf::Color::Red);
    this->window->draw(line);
    line.rotate(-45);
    line.setPosition(sf::Vector2f(75 + 140*(x+1), 110 + 140*y));
    line.rotate(135);
    this->window->draw(line);
    //this->window->draw(shape);
}

void TTTGame::drawO(const int &x, const int &y){
    // Make O
    sf::CircleShape outterCircle(50);
    outterCircle.setPosition(sf::Vector2f(110 + 140*x, 110 + 140*y));
    outterCircle.setFillColor(sf::Color(0, 0, 255));
    this->window->draw(outterCircle);
    outterCircle.setPosition(sf::Vector2f(115 + 140*x, 115 + 140*y));
    outterCircle.setRadius(45);
    outterCircle.setFillColor(this->backgroundColor);
    this->window->draw(outterCircle);
}

void TTTGame::update(){
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
    // Draw Board
    this->backgroundColor = sf::Color(255, 255, 255);
    this->drawRectangle(100, 100, 400, 400);
    this->backgroundColor = sf::Color(0, 0, 0);
    for(int i= 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if ((mousePosition.x > 100 + 140*i) && (mousePosition.x < 100 + 140*(i+1)) && 
                (mousePosition.y > 100 + 140*j) && (mousePosition.y < 100 + 140*(j+1))){
                this->backgroundColor = sf::Color(102, 102, 0);
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    this->makeMove(i, j);
                }
            }else{
                this->backgroundColor = sf::Color(0, 0, 0);
            }
            this->drawRectangle(100 + 140*i, 100 + 140*j, 125, 125);
            // Draw X's and O's here
            if(this->board[i][j] == 'X'){
                //Draw X
                this->drawX(i, j);
            }else if(this->board[i][j] == 'O'){
                // Draw O
                this->drawO(i, j);
            }
        }
    }
}


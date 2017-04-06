#include <SFML/Graphics.hpp>
#include <iostream>

#include "TTTGUI.h"
#include "TicTacToe.h"
#include "NeuralNetwork.h"

#define WIDTH 600
#define HEIGHT 600

int main(){
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Genetic Algorithm");
    
    TTTGame *game = new TTTGame(&window);
    NN *nn = new NN(game);

    sf::Time deltaTime;
	sf::Clock clock;
	while (window.isOpen()){
		window.clear();
        game->update();
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed)
				window.close();
		}
		deltaTime = clock.restart();

		// Update screen
		window.display();
	}
	return EXIT_SUCCESS;
}

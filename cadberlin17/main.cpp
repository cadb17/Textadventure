#include <iostream>
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

int main() {
	sf::RenderWindow window;
	window.create(sf::VideoMode(1000, 900), "Textadventure @ Code and Design");
	sf::Event event;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear();
		window.display();

	}
}
#include<iostream>
using namespace std;

#include "SFML/Graphics.hpp"

static void gameLogic(sf::Time deltaTime) {
	cout << deltaTime.asMicroseconds() << endl;
}

int main() {
	cout << "Launching application...";

	sf::RenderWindow window(sf::VideoMode(800, 800), "Test");
	sf::Event e;
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	sf::Clock clock;

	while (window.isOpen()) {
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed)
				window.close();
		}

		sf::Time deltaTime = clock.restart();
		gameLogic(deltaTime);

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}
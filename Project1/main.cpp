#include<iostream>
using namespace std;

#include "SFML/Graphics.hpp"

static void gameLogic(sf::Time deltaTime) { return; }

int main() {
	cout << "Launching application..." << endl;

	sf::RenderWindow window(sf::VideoMode(800, 800), "Test");
	sf::Event e;

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(10.0f, 50.0f);

	sf::Clock clock;

	int frameCount = 0;

	sf::Time counter;

	int latestFrameRate = 0;

	sf::Font font;
	if (!font.loadFromFile("Roboto-Black.ttf")) {
		cerr << ".Error while loading font" << endl;
		return -1;
	}

	sf::Text frameCounterText;
	frameCounterText.setFont(font);
	frameCounterText.setString("Loading FPS...");
	frameCounterText.setCharacterSize(16);
	frameCounterText.setFillColor(sf::Color::White);

	while (window.isOpen()) {
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
				window.close();
				cout << "Exiting application..." << endl;
			}
		}

		sf::Time deltaTime = clock.restart();
		gameLogic(deltaTime);
		counter += deltaTime;
		frameCount += 1;

		if (counter.asSeconds() >= 1) {
			counter = sf::microseconds(0);
			latestFrameRate = frameCount;
			frameCount = 0;
			frameCounterText.setString("FPS: " + to_string(latestFrameRate));
		}

		window.clear();
		window.draw(shape);
		window.draw(frameCounterText);
		window.display();
	}

	return 0;
}
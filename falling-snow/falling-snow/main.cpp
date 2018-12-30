#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <iostream>

// Window dimensions
const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 600;

void createFlake(std::vector<sf::CircleShape>& arr);

int main() {
	unsigned int elapsed = 0;
	srand((unsigned int)time(0));

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");

	std::vector<sf::CircleShape> snowflakes;
	snowflakes.reserve(150);

	while(window.isOpen()) {
		elapsed++;

		sf::Event event;
		while(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed)
				window.close();
		}

		if(elapsed >= 200 && snowflakes.size() < 150) {
			createFlake(snowflakes);
			elapsed = 0;
		}

		window.clear();
		for(unsigned int i = 0; i < snowflakes.size(); i++) {
			snowflakes[i].move(0.0f, snowflakes[i].getRadius() * 0.01f);
			window.draw(snowflakes[i]);

			if(snowflakes[i].getPosition().y >= HEIGHT) {
				snowflakes.erase(snowflakes.begin() + i);
			}
		}
		window.display();

		std::cout << snowflakes.size() << std::endl;
	}

	return 0;
}

void createFlake(std::vector<sf::CircleShape>& arr) {
	sf::CircleShape flake(float(rand()) / (float)(RAND_MAX / 3.0f) + 0.5f);
	flake.setPosition(float(rand() % WIDTH), 0.0f);
	flake.setFillColor(sf::Color::White);

	arr.emplace_back(flake);
}
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <iostream>

// Window dimensions
const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 600;

void createFlake(std::vector<sf::CircleShape>& arr);

int main() {
	unsigned int elapsed = 0;		// Elapsed time since last snowflake spawn
	srand((unsigned int)time(0));	// Random seeding

	unsigned int numOfSnowflakes;
	std::cout << "Max number of snowflakes present on the screen. (0 for default): ";
	std::cin >> numOfSnowflakes;

	unsigned int delay;
	std::cout << "Delay between spawns. (0 for default): ";
	std::cin >> delay;

	// Default values
	if(numOfSnowflakes == 0)
		numOfSnowflakes = 200;
	if(delay == 0)
		delay = 10;

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");
	window.setFramerateLimit(120);

	std::vector<sf::CircleShape> snowflakes;
	snowflakes.reserve(numOfSnowflakes);

	while(window.isOpen()) {
		elapsed++;

		sf::Event event;
		while(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed)
				window.close();
		}

		// If the delay has passed and the max num of snowflakes isn't reached, create another
		if(elapsed >= delay && snowflakes.size() < numOfSnowflakes) {
			createFlake(snowflakes);
			elapsed = 0;
		}

		window.clear();

		for(unsigned int i = 0; i < snowflakes.size(); i++) {
			snowflakes[i].move(0.0f, snowflakes[i].getRadius() * 0.4f);
			window.draw(snowflakes[i]);

			// Don't draw snowflakes that are outside of the window
			if(snowflakes[i].getPosition().y >= HEIGHT) {
				snowflakes.erase(snowflakes.begin() + i);
			}
		}

		window.display();
	}
	return 0;
}

// Create a snowflake and store it in an array
void createFlake(std::vector<sf::CircleShape>& arr) {
	sf::CircleShape flake(float(rand()) / (float)(RAND_MAX / 3.0f) + 0.5f);
	flake.setPosition(float(rand() % WIDTH), 0.0f);
	flake.setFillColor(sf::Color::White);

	arr.emplace_back(flake);
}
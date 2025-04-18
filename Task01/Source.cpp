#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

float step = 1;
float x = 0, y = 0;
sf::CircleShape shape(70.f);

static void MoveVertical() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		y -= step;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		y += step;
}

static void MoveHorizontal() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		x -= step;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		x += step;
}
int main()
{
	sf::RenderWindow window(sf::VideoMode({ 1000, 1000 }), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}
		// Movement functions
		MoveVertical();
		MoveHorizontal();
		shape.setPosition({ x, y });

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}


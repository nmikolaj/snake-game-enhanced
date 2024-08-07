#ifndef SNAKE_SCIANA_HPP
#define SNAKE_SCIANA_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

class Sciana {
private:
	RectangleShape ksztaltSciany;

public:
	Sciana(Vector2f pozycja, Vector2f wielkosc);

	RectangleShape getShape();
};

#endif
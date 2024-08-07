#ifndef SNAKE_JABLKO_HPP
#define SNAKE_JABLKO_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

class Jablko {
	friend class Engine;
private:
	RectangleShape jbk;
public:
	Jablko();

	void setPosition(Vector2f newPosition);

	RectangleShape getJbk();
};

#endif

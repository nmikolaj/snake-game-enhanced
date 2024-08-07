#include "jablko.hpp"

Jablko::Jablko() {
	Vector2f startingPosition(300, 400);
	jbk.setSize(Vector2f(20, 20));
	jbk.setFillColor(Color::Red);
	jbk.setPosition(startingPosition);

}

void Jablko::setPosition(Vector2f newPosition) {
	jbk.setPosition(newPosition);
}

RectangleShape Jablko::getJbk() {
	return jbk;
}
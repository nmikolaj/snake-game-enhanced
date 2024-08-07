#include "snakeInfo.hpp"

SnakeInfo::SnakeInfo(Vector2f startPosition) {
	section.setSize(Vector2f(20, 20));
	section.setFillColor(Color::Green);
	section.setPosition(startPosition);
	position = startPosition;
}

Vector2f SnakeInfo::getPosition() {
	return position;
}

void SnakeInfo::setPosition(Vector2f newPosition) {
	position = newPosition;
}

RectangleShape SnakeInfo::getShape() {
	return section;
}

void SnakeInfo::update() {
	section.setPosition(position);
}
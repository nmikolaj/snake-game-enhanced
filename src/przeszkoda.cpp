#include "przeszkoda.hpp"


void Pochodna::pochodnaInit() {
	Vector2f startingPosition(820, 0);
	phd.setSize(Vector2f(20, 20));
	phd.setFillColor(Color::Yellow);
	phd.setPosition(startingPosition);
	position = startingPosition;
}

void Pochodna::setPositionPhd(Vector2f newPosition) {
	position = newPosition;
	phd.setPosition(newPosition);
}

Vector2f Pochodna::getPosition() {
	return position;
}

RectangleShape Pochodna::getPhd() {
	return phd;
}



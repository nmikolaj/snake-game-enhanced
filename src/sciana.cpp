#include "sciana.hpp"

Sciana::Sciana(Vector2f pozycja, Vector2f wielkosc) {
	ksztaltSciany.setSize(wielkosc);
	ksztaltSciany.setFillColor(Color::White);
	ksztaltSciany.setPosition(pozycja);
}

RectangleShape Sciana::getShape() {
	return ksztaltSciany;
}
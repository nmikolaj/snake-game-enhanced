#include "sciana.hpp"

Sciana::Sciana(Vector2f pozycja, Vector2f wielkosc) {
	ksztaltSciany.setSize(wielkosc);
	ksztaltSciany.setFillColor(Color(120, 120, 120));
	ksztaltSciany.setPosition(pozycja);
}

RectangleShape Sciana::getShape() {
	return ksztaltSciany;
}
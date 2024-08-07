#ifndef SNAKE_POCHODNA_HPP
#define SNAKE_POCHODNA_HPP

//#include "engine.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;


class Pochodna{
private:
	RectangleShape phd;
	Vector2f position;

	friend class Engine;
public:
	void pochodnaInit();

	void setPositionPhd(Vector2f newPosition);

	Vector2f getPosition();

	RectangleShape getPhd();

	//void zmienPozPrzeszkody();
};

#endif
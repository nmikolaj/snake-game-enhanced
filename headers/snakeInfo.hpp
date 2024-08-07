#ifndef SNAKE_SNAKEINFO_HPP
#define SNAKE_SNAKEINFO_HPP

#include <SFML/Graphics.hpp>

using namespace sf;


class SnakeInfo {
	friend class Engine; // deklaracja przyjaciela (uzyte w Engine::updatePrzetrwanie() w dostepie do snake.section)
private:
	Vector2f position;
	RectangleShape section;

public:
	SnakeInfo(Vector2f startPosition);

	Vector2f getPosition();

	void setPosition(Vector2f newPosition);

	RectangleShape getShape();

	void update();

};

#endif 
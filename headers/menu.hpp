#ifndef SNAKE_MENU_HPP
#define SNAKE_MENU_HPP

#define MAX_ILOSC_OPCJI 4

#include "engine.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

using namespace sf;

class Menu {
private:
	Font fontMenu;
	Text textMenu[MAX_ILOSC_OPCJI];
	Color zmiennaKolor;

	int zaznaczonaOpcja;

public:
	Menu(float szerokosc, float wysokosc);

	void menuDraw(RenderWindow & m_window);

	void moveUp();
	void moveDown();

	int getWybranaOpcja();
};

#endif
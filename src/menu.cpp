#include "menu.hpp"

Menu::Menu(float szerokosc, float wysokosc) {
	if (!fontMenu.loadFromFile("assets/fonts/ka1.ttf")) {
		std::cout << "ERROR::GAME::INITFONTS::Nie zaladowano czcionki!\n";
	}

	textMenu[0].setFont(fontMenu);
	textMenu[0].setCharacterSize(40);
	textMenu[0].setFillColor(Color::Green);
	textMenu[0].setString("SNAKE");
	textMenu[0].setOutlineColor(Color::Blue);
	textMenu[0].setOutlineThickness(-1);
	FloatRect textMenuGranice = textMenu[0].getLocalBounds();
	textMenu[0].setPosition(Vector2f(szerokosc / 2 - textMenuGranice.width / 2, wysokosc / (MAX_ILOSC_OPCJI+1) * 1));

	textMenu[1].setFont(fontMenu);
	textMenu[1].setCharacterSize(30);
	textMenu[1].setFillColor(Color::Red);
	textMenu[1].setString("Tryb Klasyczny");
	FloatRect textMenuGranice2 = textMenu[1].getLocalBounds();
	textMenu[1].setPosition(Vector2f(szerokosc / 2 - textMenuGranice2.width / 2, wysokosc / (MAX_ILOSC_OPCJI + 1) * 2));

	textMenu[2].setFont(fontMenu);
	textMenu[2].setCharacterSize(30);
	textMenu[2].setFillColor(Color::Green);
	textMenu[2].setString("Tryb Przetrwania");
	FloatRect textMenuGranice3 = textMenu[2].getLocalBounds();
	textMenu[2].setPosition(Vector2f(szerokosc / 2 - textMenuGranice3.width / 2, wysokosc / (MAX_ILOSC_OPCJI + 1) * 3));
	
	textMenu[3].setFont(fontMenu);
	textMenu[3].setCharacterSize(30);
	textMenu[3].setFillColor(Color::Green);
	textMenu[3].setString("Wyjscie");
	FloatRect textMenuGranice4 = textMenu[3].getLocalBounds();
	textMenu[3].setPosition(Vector2f(szerokosc / 2 - textMenuGranice4.width / 2, wysokosc / (MAX_ILOSC_OPCJI + 1) * 4));

	zaznaczonaOpcja = 1;
	//zmiennaKolor = Color::Red;
}


void Menu::menuDraw(RenderWindow &m_window) {
	for (int i = 0; i < MAX_ILOSC_OPCJI; i++) {
		m_window.draw(textMenu[i]);
	}
}

void Menu::moveUp() {
	if (zaznaczonaOpcja - 1 > 0) {
		//zmiennaKolor = textMenu[zaznaczonaOpcja].getFillColor();
		textMenu[zaznaczonaOpcja].setFillColor(Color::Green);
		zaznaczonaOpcja--;
		textMenu[zaznaczonaOpcja].setFillColor(Color::Red);
	}
}

void Menu::moveDown() {
	if (zaznaczonaOpcja + 1 < MAX_ILOSC_OPCJI ) {
		textMenu[zaznaczonaOpcja].setFillColor(Color::Green);
		zaznaczonaOpcja++;
		textMenu[zaznaczonaOpcja].setFillColor(Color::Red);
	}
}

int Menu::getWybranaOpcja() {
	return zaznaczonaOpcja;
}
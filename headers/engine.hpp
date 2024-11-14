#ifndef SNAKE_ENGINE_HPP
#define SNAKE_ENGINE_HPP

#include "snakeInfo.hpp"
#include "jablko.hpp"
#include "sciana.hpp"
#include "przeszkoda.hpp"
#include <iostream>
#include <cstdlib> //rand()
#include <ctime> //rand()
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>
#include <iterator>
#include <deque>

using namespace sf;
using namespace std;

class Engine : public Pochodna {
	friend class Menu;
	friend class Pochodna;
private:
	// okno
	Vector2f resolution;
	RenderWindow window;
	const unsigned int FPS = 60;
	static const Time TimePerFrame;

	//Zasoby
	Font font, fontKoniecGry;
	Text text, textKoniecGry, textPauza, textPauzaPrzetrwanie;

	vector<SnakeInfo> snake;
	vector<int> ar;
	vector<int>::iterator ptr;

	int snakeKierunek;
	deque<int> kolejkaKierunku; // kolejka dla wczytanych przyciskow kierunkowych
	int predkosc;

	unsigned long long int zjedzoneJablka;
	int czesciDoDodania; // po zjedzeniu jablka
	Jablko jablko;
	bool supermoc, supermocCzas;

	Pochodna przeszkoda;

	vector<Sciana> sciany;

	Time timeSinceLastMove;

	int obecnyStanGry;
	int ostatniStanGry;

	int wynik;
	int wynikPrzetrwanie;

public:

	enum Kierunek { GORA, PRAWO, DOL, LEWO };
	enum StanGry {GRA, PAUZA, KONIEC};
	// konstruktor
	Engine();
	// destruktor
	~Engine();

	void initText();
	void initTextPrzetrwanie();
	void initTextKoniecGry();
	void initTextPauza(sf::Text& text, const sf::Font& font, const std::string& string,
		unsigned int characterSize, const sf::Color& fillColor,
		const sf::Color& outlineColor, float outlineThickness,
		const Vector2f& position);

	void input();
	void inputPrzetrwanie(); // wystarczy dodac ifa do input() ale moze w przyszlosci bedzie wiecej roznic

	void dodajKierunek(int nowyKierunek);
	void update();
	void updatePrzetrwanie();

	void draw();
	void drawPrzetrwanie();

	void newSnake();

	void addSnakeSection();

	void zmienPozJablka();
	void zmienPozPrzeszkody();

	void stworzSciany();
	void dodajSciane();

	void przelaczPauze();

	void rozpocznijGre();
	void rozpocznijGrePrzetrwanie();

	void run();
	void runPrzetrwanie();

	void initOkno();

};


#endif //SNAKE_ENGINE_HPP
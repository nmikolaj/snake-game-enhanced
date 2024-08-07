#include "engine.hpp"

void Engine::draw() {
	window.clear(Color::Black);
	//sciany
	for (auto& a : sciany) {
		window.draw(a.getShape());
	}
	

	//jablko
	window.draw(jablko.getJbk());

	//czesci snake
	for (auto& s : snake) { //s to czesc vectora snake
		window.draw(s.getShape());
	}

	//text
	window.draw(text);

	//pauza
	if (obecnyStanGry == StanGry::PAUZA) {
		window.draw(textPauza);
	}

	//koniec gry
	if (obecnyStanGry == StanGry::KONIEC) {
		for (auto& a : sciany) {
			window.draw(a.getShape());
		}
		window.draw(jablko.getJbk());
		window.draw(text);
		window.draw(textKoniecGry);
	}
	window.display();
}
// Snake.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "engine.hpp"
#include "menu.hpp"
#include <iostream>

using namespace std;

int main()
{
	RenderWindow window(VideoMode(600, 600), "SNAKE MENU");
	Menu menu(window.getSize().x, window.getSize().y);

	Engine engine;

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {

			case Event::Closed:
				window.close();
				break;

			case Event::KeyReleased:
				switch (event.key.code) {

				case Keyboard::Up:
					menu.moveUp();
					break;

				case Keyboard::Down:
					menu.moveDown();
					break;

				case Keyboard::Return:
					switch (menu.getWybranaOpcja()) {

					case 1:
						cout << "Nacisnieto opcje Gra Klasyczna" << endl;
						engine.initOkno();
						engine.rozpocznijGre();
						engine.initText();
						engine.run();
						break;

					case 2:
						cout << "Nacisnieto opcje Tryb Przetrwania" << endl;
						engine.initOkno();
						engine.rozpocznijGrePrzetrwanie();
						engine.initTextPrzetrwanie();
						engine.runPrzetrwanie();
						break;

					case 3:
						window.close();
						break;
					}
				}
			}
		}
		window.clear();

		menu.menuDraw(window);

		window.display();
	}
	

	return 0;
}
#include "engine.hpp"

const sf::Time Engine::TimePerFrame = seconds(1.f / 60.f);
Engine::~Engine() {
	cout << "Destruktor wywolany!" << endl;
}


// konstruktor
Engine::Engine() {
	resolution = Vector2f(800, 600);
	//window.create(VideoMode(resolution.x, resolution.y), "Snake", Style::Default); // dzieki default powstaje okno a nie fullscreen
	//window.setFramerateLimit(FPS);

	//rozpocznijGre();

	if (!font.loadFromFile("assets/fonts/Freshman.ttf")) {
		std::cout << "ERROR::GAME::INITFONTS::Nie zaladowano czcionki!\n";
	}
	if (!fontKoniecGry.loadFromFile("assets/fonts/ka1.ttf")) {
		std::cout << "ERROR::GAME::INITFONTS::Nie zaladowano czcionki!\n";
	}

	ar = { 1, 2, 3, 4, 5 };
	ptr = ar.begin();

	textKoniecGry.setFont(fontKoniecGry);
	textKoniecGry.setCharacterSize(40);
	textKoniecGry.setFillColor(Color::Blue);
	textKoniecGry.setString("KONIEC GRY");
	FloatRect textKoniecGryGranice = textKoniecGry.getLocalBounds();
	textKoniecGry.setPosition(Vector2f(resolution.x / 2 - textKoniecGryGranice.width / 2, 100));

	textPauza.setFont(font);
	textPauza.setCharacterSize(40);
	textPauza.setFillColor(Color::Yellow);
	textPauza.setOutlineColor(Color::Blue);
	textPauza.setOutlineThickness(2);
	textPauza.setString("    PAUZA\n\n Highscore: \n\n" + to_string(*ptr) + ". \t\t\t0");
	FloatRect textPauzaGranice = textPauza.getLocalBounds();
	textPauza.setPosition(Vector2f(resolution.x / 2 - textPauzaGranice.width / 2, 100));

	textPauzaPrzetrwanie.setFont(font);
	textPauzaPrzetrwanie.setCharacterSize(40);
	textPauzaPrzetrwanie.setFillColor(Color::Yellow);
	textPauzaPrzetrwanie.setString("    PAUZA\n\n Highscore: \n\n" + to_string(*ptr) + ". \t\t\t0");
	FloatRect textPauzaPrzetrwanieGranice = textPauzaPrzetrwanie.getLocalBounds();
	textPauzaPrzetrwanie.setPosition(Vector2f(resolution.x / 2 - textPauzaPrzetrwanieGranice.width / 2, 100));

}

void Engine::initOkno() {
	resolution = Vector2f(800, 600);
	window.create(VideoMode(resolution.x, resolution.y), "Snake", Style::Default); // dzieki default powstaje okno a nie fullscreen
	window.setFramerateLimit(FPS);
}

void Engine::initText() {
	text.setFont(font);
	text.setCharacterSize(14);
	text.setFillColor(Color::Blue);
	text.setString("JABLKA: " + to_string(zjedzoneJablka));
	text.setPosition(Vector2f(15, 0));
}

void Engine::initTextPrzetrwanie() {
	text.setFont(font);
	text.setCharacterSize(14);
	text.setFillColor(Color::Blue);
	text.setString("WYNIK: " + to_string(zjedzoneJablka));
	text.setPosition(Vector2f(15, 0));
}


void Engine::rozpocznijGre() {
	zjedzoneJablka = 0;
	wynik = 0;

	predkosc = 2;
	snakeKierunek = Kierunek::PRAWO;

	timeSinceLastMove = Time::Zero;

	czesciDoDodania = 0;

	kolejkaKierunku.clear();

	obecnyStanGry == StanGry::GRA;
	ostatniStanGry == obecnyStanGry;

	sciany.clear();
	stworzSciany();
	newSnake();
	zmienPozJablka();

	jablko.jbk.setFillColor(Color::Red);
}

void Engine::rozpocznijGrePrzetrwanie() {
	zjedzoneJablka = 0;
	wynikPrzetrwanie = 0;

	predkosc = 15;
	snakeKierunek = Kierunek::PRAWO;

	timeSinceLastMove = Time::Zero;

	czesciDoDodania = 25;

	kolejkaKierunku.clear();

	supermoc = false;
	supermocCzas = false;

	obecnyStanGry == StanGry::GRA;
	ostatniStanGry == obecnyStanGry;

	sciany.clear();
	stworzSciany();
	newSnake();
	zmienPozJablka();

	jablko.jbk.setFillColor(Color::Cyan); // klasa zaprzyjazniona
}

void Engine::input() {
	Event event{};

	while (window.pollEvent(event)) {
		//zamkniecie okna
		if (event.type == Event::Closed) window.close();

		//obsluga klawiatury
		if (event.type == Event::KeyPressed) {
			//wyjdz
			if (event.key.code == Keyboard::Escape) {
				window.close();
			}
			if (event.key.code == Keyboard::P && obecnyStanGry != StanGry::PAUZA && obecnyStanGry != StanGry::KONIEC) {
				obecnyStanGry = StanGry::PAUZA;
			}
			else if(event.key.code == Keyboard::P && obecnyStanGry == StanGry::PAUZA && obecnyStanGry != StanGry::KONIEC){
				obecnyStanGry = StanGry::GRA;
			}
			if (obecnyStanGry == StanGry::KONIEC) {
				if (event.key.code == Keyboard::Enter) {
					rozpocznijGre();
					obecnyStanGry = StanGry::GRA;
				}
			}
			if (event.key.code == Keyboard::Up) {
				dodajKierunek(Kierunek::GORA);
			}
			else if(event.key.code == Keyboard::Down) {
				dodajKierunek(Kierunek::DOL);
			}
			else if (event.key.code == Keyboard::Right) {
				dodajKierunek(Kierunek::PRAWO);
			}
			else if (event.key.code == Keyboard::Left) {
				dodajKierunek(Kierunek::LEWO);
			}

		}
		
	}
}

void Engine::inputPrzetrwanie() {
	Event event{};

	while (window.pollEvent(event)) {
		//zamkniecie okna
		if (event.type == Event::Closed) window.close();

		//obsluga klawiatury
		if (event.type == Event::KeyPressed) {
			//wyjdz
			if (event.key.code == Keyboard::Escape) {
				window.close();
			}
			if (event.key.code == Keyboard::P && obecnyStanGry != StanGry::PAUZA && obecnyStanGry != StanGry::KONIEC) {
				obecnyStanGry = StanGry::PAUZA;
			}
			else if (event.key.code == Keyboard::P && obecnyStanGry == StanGry::PAUZA && obecnyStanGry != StanGry::KONIEC) {
				obecnyStanGry = StanGry::GRA;
			}
			if (obecnyStanGry == StanGry::KONIEC) {
				if (event.key.code == Keyboard::Enter) {
					rozpocznijGrePrzetrwanie(); // tutaj roznica
					obecnyStanGry = StanGry::GRA;
				}
			}
			if (event.key.code == Keyboard::Up) {
				dodajKierunek(Kierunek::GORA);
			}
			else if (event.key.code == Keyboard::Down) {
				dodajKierunek(Kierunek::DOL);
			}
			else if (event.key.code == Keyboard::Right) {
				dodajKierunek(Kierunek::PRAWO);
			}
			else if (event.key.code == Keyboard::Left) {
				dodajKierunek(Kierunek::LEWO);
			}

		}

	}
}

//snake stworzony na poczatku kazdego poziomu
void Engine::newSnake() {
	snake.clear();
	snake.emplace_back(Vector2f(100, 100)); //wklada na koniec wektora nowa pozycje
	snake.emplace_back(Vector2f(80, 100));
	snake.emplace_back(Vector2f(60, 100));
}

//dodaje czesc snake na ostatniej jego pozycji
void Engine::addSnakeSection() {
	Vector2f newSectionPosition = snake[snake.size() - 1].getPosition();
	snake.emplace_back(newSectionPosition);
}

void Engine::dodajKierunek(int nowyKierunek) {
	if (kolejkaKierunku.empty()) {
		kolejkaKierunku.emplace_back(nowyKierunek);
	}
	else {
		if (kolejkaKierunku.back() != nowyKierunek) {	// sprawdza ostatni element kolejki
			kolejkaKierunku.emplace_back(nowyKierunek);
		}
	}
}

void Engine::update() {
	//aktualizuj pozycje snake
	if (timeSinceLastMove.asSeconds() >= seconds(1.f / float(predkosc)).asSeconds()) {
		Vector2f thisSectionPosition = snake[0].getPosition();
		Vector2f lastSectionPosition = thisSectionPosition;

		// czy jest cos w kolejce wejscia
		if (!kolejkaKierunku.empty()) {
			// sprawdzam czy snake nie robi zawrotu
			switch (snakeKierunek) {
				case Kierunek::GORA:
					if (kolejkaKierunku.front() != Kierunek::DOL) {
						snakeKierunek = kolejkaKierunku.front();
					}
					break;
				case Kierunek::DOL:
					if (kolejkaKierunku.front() != Kierunek::GORA) {
						snakeKierunek = kolejkaKierunku.front();
					}
					break;
				case Kierunek::PRAWO:
					if (kolejkaKierunku.front() != Kierunek::LEWO) {
						snakeKierunek = kolejkaKierunku.front();
					}
					break;
				case Kierunek::LEWO:
					if (kolejkaKierunku.front() != Kierunek::PRAWO) {
						snakeKierunek = kolejkaKierunku.front();
					}
					break;
			}
			kolejkaKierunku.pop_front();
		}

		if (czesciDoDodania) {
			addSnakeSection();
			czesciDoDodania--;
		}

		// nowa pozycja glowy
		switch (snakeKierunek) {
			case Kierunek::PRAWO:
				snake[0].setPosition(Vector2f(thisSectionPosition.x + 20, thisSectionPosition.y)); // kawalki maja po 20 pixeli
				break;
			case Kierunek::LEWO:
				snake[0].setPosition(Vector2f(thisSectionPosition.x - 20, thisSectionPosition.y)); // kawalki maja po 20 pixeli
				break;
			case Kierunek::GORA:
				snake[0].setPosition(Vector2f(thisSectionPosition.x, thisSectionPosition.y - 20)); // kawalki maja po 20 pixeli
				break;
			case Kierunek::DOL:
				snake[0].setPosition(Vector2f(thisSectionPosition.x, thisSectionPosition.y + 20)); // kawalki maja po 20 pixeli
				break;

		}

		//nowa pozycja tulowia
		for (int i = 1; i < snake.size(); i++) {
			thisSectionPosition = snake[i].getPosition();
			snake[i].setPosition(lastSectionPosition);
			lastSectionPosition = thisSectionPosition;
		}

		// uzycie funkcji update do wszystkich kawalkow snake
		for (auto & s : snake) { // ?
			s.update();
		}

		//kolizje
		if (snake[0].getShape().getGlobalBounds().intersects(jablko.getJbk().getGlobalBounds())) {
			zjedzoneJablka++;
			czesciDoDodania += 3;
			predkosc++;
			zmienPozJablka();
		}

		for (int i = 1; i < snake.size(); i++) {
			if(snake[0].getShape().getGlobalBounds().intersects(snake[i].getShape().getGlobalBounds()))
				obecnyStanGry = StanGry::KONIEC;
		}
		for (int i = 1; i < sciany.size(); i++) {
			if (snake[0].getShape().getGlobalBounds().intersects(sciany[i].getShape().getGlobalBounds()))
				obecnyStanGry = StanGry::KONIEC;
		}


		// resetuje czasomierz
		timeSinceLastMove = Time::Zero;
	}
}

void Engine::updatePrzetrwanie() {

	//aktualizuj pozycje snake
	if (timeSinceLastMove.asSeconds() >= seconds(1.f / float(predkosc)).asSeconds()) {
		Vector2f thisSectionPosition = snake[0].getPosition();
		Vector2f lastSectionPosition = thisSectionPosition;

		// czy jest cos w kolejce wejscia
		if (!kolejkaKierunku.empty()) {
			// sprawdzam czy snake nie robi zawrotu
			switch (snakeKierunek) {
			case Kierunek::GORA:
				if (kolejkaKierunku.front() != Kierunek::DOL) {
					snakeKierunek = kolejkaKierunku.front();
				}
				break;
			case Kierunek::DOL:
				if (kolejkaKierunku.front() != Kierunek::GORA) {
					snakeKierunek = kolejkaKierunku.front();
				}
				break;
			case Kierunek::PRAWO:
				if (kolejkaKierunku.front() != Kierunek::LEWO) {
					snakeKierunek = kolejkaKierunku.front();
				}
				break;
			case Kierunek::LEWO:
				if (kolejkaKierunku.front() != Kierunek::PRAWO) {
					snakeKierunek = kolejkaKierunku.front();
				}
				break;
			}
			kolejkaKierunku.pop_front();
		}

		if (czesciDoDodania) {
			addSnakeSection();
			czesciDoDodania--;
		}

		// nowa pozycja glowy
		switch (snakeKierunek) {
		case Kierunek::PRAWO:
			snake[0].setPosition(Vector2f(thisSectionPosition.x + 20, thisSectionPosition.y)); // kawalki maja po 20 pixeli
			break;
		case Kierunek::LEWO:
			snake[0].setPosition(Vector2f(thisSectionPosition.x - 20, thisSectionPosition.y)); // kawalki maja po 20 pixeli
			break;
		case Kierunek::GORA:
			snake[0].setPosition(Vector2f(thisSectionPosition.x, thisSectionPosition.y - 20)); // kawalki maja po 20 pixeli
			break;
		case Kierunek::DOL:
			snake[0].setPosition(Vector2f(thisSectionPosition.x, thisSectionPosition.y + 20)); // kawalki maja po 20 pixeli
			break;
		}

		//nowa pozycja tulowia
		for (int i = 1; i < snake.size(); i++) {
			thisSectionPosition = snake[i].getPosition();
			snake[i].setPosition(lastSectionPosition);
			lastSectionPosition = thisSectionPosition;
		}

		// uzycie funkcji update do wszystkich kawalkow snake
		for (auto& s : snake) { // ?
			s.update();
		}

		//nowa pozycja przeszkody
		przeszkoda.setPositionPhd(Vector2f (przeszkoda.getPosition().x + 20, przeszkoda.getPosition().y)); //TODO

		//przeszkoda.phd.setPosition(przeszkoda.position);


		//kolizje
		if (snake[0].getShape().getGlobalBounds().intersects(jablko.getJbk().getGlobalBounds())) {
			supermoc = true;
			supermocCzas = true;
			//czesciDoDodania += 3;
			//predkosc++;
			//zmienPozJablka();
		}
		if (supermoc) {
			for (int i = 0; i < snake.size(); i++) {
				snake[i].section.setFillColor(Color::Blue); // zmiana koloru snake
			}
		}
		if (!supermoc) {
			for (int i = 1; i < snake.size(); i++) {
				if (snake[0].getShape().getGlobalBounds().intersects(snake[i].getShape().getGlobalBounds()))
					obecnyStanGry = StanGry::KONIEC;
			}
			for (int i = 1; i < sciany.size(); i++) {
				if (snake[0].getShape().getGlobalBounds().intersects(sciany[i].getShape().getGlobalBounds()))
					obecnyStanGry = StanGry::KONIEC;
			}
			for (int i = 0; i < snake.size(); i++) {
				if (przeszkoda.getPhd().getGlobalBounds().intersects(snake[i].getShape().getGlobalBounds())) {
					obecnyStanGry = StanGry::KONIEC;
				}
			}
		}

		// resetuje czasomierz
		timeSinceLastMove = Time::Zero;
	}
}

void Engine::zmienPozJablka() {
	//wstawienie jablka w miejsce poza snake i scianami
	Vector2f rozmiarJablka = Vector2f(resolution.x / 20 - 2, resolution.y / 20 - 2);
	Vector2f nowaPozJablka;
	bool k = true;
	//srand(time(nullptr));
	while (k) {
		nowaPozJablka.x = (float)(1 + rand() / ((RAND_MAX + 1u) / (int)rozmiarJablka.x)) * 20;
		nowaPozJablka.y = (float)(1 + rand() / ((RAND_MAX + 1u) / (int)rozmiarJablka.y)) * 20;
		//czy w snake
		k = false;
		for (auto & s : snake) {
			if (s.getShape().getGlobalBounds().intersects(Rect<float>(nowaPozJablka.x, nowaPozJablka.y, 20, 20))) {
				k = true;
				break;
			}
		}
		for (auto & w : sciany) {
			if (w.getShape().getGlobalBounds().intersects(Rect<float>(nowaPozJablka.x, nowaPozJablka.y, 20, 20))) {
				k = true;
				break;
			}
		}
	}
	//jablko.setPosition(Vector2f (800, 0)); todo
	jablko.setPosition(nowaPozJablka);
}

void Engine::zmienPozPrzeszkody() {
	//analogicznie jak jablko
	Vector2f rozmiarJablka = Vector2f(resolution.x / 20 - 2, resolution.y / 20 - 2);
	Vector2f nowaPozJablka;
	bool k = true;
	//srand(time(NULL));
	while (k) {
		//nowaPozJablka.x = (float)(1 + rand() / ((RAND_MAX + 1u) / (int)rozmiarJablka.x)) * 20;
		nowaPozJablka.x = (float)(20);
		nowaPozJablka.y = (float)(1 + rand() / ((RAND_MAX + 1u) / (int)rozmiarJablka.y)) * 20;
		// czy w snake
		k = false;
		for (auto& s : snake) {
			if (s.getShape().getGlobalBounds().intersects(Rect<float>(nowaPozJablka.x, nowaPozJablka.y, 20, 20))) {
				k = true;
				break;
			}
		}
		for (auto& w : sciany) {
			if (w.getShape().getGlobalBounds().intersects(Rect<float>(nowaPozJablka.x, nowaPozJablka.y, 20, 20))) {
				k = true;
				break;
			}
		}
	}
	przeszkoda.setPositionPhd(nowaPozJablka);
}


void Engine::stworzSciany() {
	for (int x = 0; x < 40; x++) {
		sciany.emplace_back(Sciana(Vector2f(x * 20, 0), Vector2f(20, 20)));
		sciany.emplace_back(Sciana(Vector2f(x * 20, 580), Vector2f(20, 20)));
	}
	for (int y = 0; y < 60; y++) {
		sciany.emplace_back(Sciana(Vector2f(0, y * 20), Vector2f(20, 20)));
		sciany.emplace_back(Sciana(Vector2f(780, y * 20), Vector2f(20, 20)));
	}

}

void Engine::dodajSciane() {
	//srand(time(nullptr));
	Vector2f rozmiarSciany = Vector2f(resolution.x / 20 - 2, resolution.y / 20 - 2);
	Vector2f nowaPozSciany;
	bool k = true;
	while (k) {
		nowaPozSciany.x = (float)(1 + rand() / ((RAND_MAX + 1u) / (int)rozmiarSciany.x)) * 20;
		nowaPozSciany.y = (float)(1 + rand() / ((RAND_MAX + 1u) / (int)rozmiarSciany.y)) * 20;
		//czy w snake
		k = false;
		for (auto& s : snake) {
			if (s.getShape().getGlobalBounds().intersects(Rect<float>(nowaPozSciany.x, nowaPozSciany.y, 20, 20))) {
				k = true;
				break;
			}
		}
		for (auto& w : sciany) {
			if (w.getShape().getGlobalBounds().intersects(Rect<float>(nowaPozSciany.x, nowaPozSciany.y, 20, 20))) {
				k = true;
				break;
			}
		}
	}
	sciany.emplace_back(Sciana(nowaPozSciany, Vector2f(20, 20)));
}

void Engine::drawPrzetrwanie() {
	window.clear(Color::Black);
	//sciany
	for (auto& a : sciany) {
		window.draw(a.getShape());
	}
	//przeszkoda
	window.draw(przeszkoda.getPhd());

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
		window.draw(textPauzaPrzetrwanie);
	}

	//koniec gry
	if (obecnyStanGry == StanGry::KONIEC) {
		for (auto& a : sciany) {
			window.draw(a.getShape());
		}
		window.draw(przeszkoda.getPhd());
		window.draw(jablko.getJbk());
		window.draw(text);
		window.draw(textKoniecGry);
	}
	window.display();
}

void Engine::run() {
	srand(time(NULL));
	Clock clock;
	// petla main dziala do czasu zamkniecia okna
	while (window.isOpen()) {
		Time dt = clock.restart(); // roznica czasu od wyzerowania czasomierza

		if (obecnyStanGry == StanGry::KONIEC || obecnyStanGry == StanGry::PAUZA) {
			//czekaj na przycisk
			input();
			// narysuj okno pauzy
			if (obecnyStanGry == StanGry::PAUZA) {
				draw();
			}
			//narysuj okno konca gry i zapisz wynik
			if (obecnyStanGry == StanGry::KONIEC) {
				draw();
				if (zjedzoneJablka > wynik) {
					wynik = zjedzoneJablka;
					textPauza.setString("    PAUZA\n\n Highscore: \n\n" + to_string(*ptr) + ": \t\t\t" + to_string(wynik));
				}
			}
			sleep(milliseconds(2)); //zeby odciazyc cpu
			continue; 
		}

		timeSinceLastMove += dt;

		initText();
		input();
		update();
		draw();
	}
}

void Engine::runPrzetrwanie() {

	srand(time(NULL));
	przeszkoda.pochodnaInit();
	Clock clock;
	int cykliczna = 0;
	int zmienna = 0;
	int k = 0, j = 0, l = 0;

	// petla main dziala do czasu zamkniecia okna
	while (window.isOpen()) {
		Time dt = clock.restart(); // roznica czasu od wyzerowania czasomierza

		if (obecnyStanGry == StanGry::KONIEC || obecnyStanGry == StanGry::PAUZA) {
			//czekaj na przycisk
			inputPrzetrwanie();
			// narysuj okno pauzy
			if (obecnyStanGry == StanGry::PAUZA) {
				drawPrzetrwanie();
			}
			//narysuj okno konca gry
			if (obecnyStanGry == StanGry::KONIEC) {
				drawPrzetrwanie();
				if (zjedzoneJablka > wynikPrzetrwanie) {
					wynikPrzetrwanie = zjedzoneJablka;
					textPauzaPrzetrwanie.setString("    PAUZA\n\n Highscore: \n\n" + to_string(*ptr) + ": \t\t\t" + to_string(wynikPrzetrwanie));
				}
			}
			sleep(milliseconds(2)); //zeby odciazyc cpu
			continue;
		}
		
		if (supermocCzas) {  // reset licznika przy uzyskaniu supermocy
			supermocCzas = false;
			jablko.setPosition(Vector2f(800, 0)); // zabranie jablka z pola
			cykliczna = 0; 
		}
		cykliczna++;
		// algorytm
		if (cykliczna == 500 ) { // bez && supermoc==true zeby cykliczna nie rosla w nieskonczonosc
			supermoc = false;	//problem ze nie zawsze w tym samym momencie sie odpali i nie zawsze bedzie dzialac 10 przejsc
			for (int i = 0; i < snake.size(); i++) {
				snake[i].section.setFillColor(Color::Green); // zmiana koloru snake
			}
			cykliczna = 0;
		}

		zmienna++;
		if (zmienna == 100) { // licznik punktow
			zjedzoneJablka++;
			k++;
			j++;
			l++;
			zmienna = 0;
		}
		if (l == 10) {
			dodajSciane();
			predkosc += 2;
			czesciDoDodania += 3;
			l = 0;
		}
		if (k == 6) {
			zmienPozPrzeszkody();
			k = 1;
		}
		if (j == 13) {
			zmienPozJablka();
			j = 0;
		}
		if (j == 3) { // znikanie jablka
			jablko.setPosition(Vector2f(800, 0));
		}



		timeSinceLastMove += dt;

		initTextPrzetrwanie();
		inputPrzetrwanie();
		updatePrzetrwanie();
		drawPrzetrwanie();
	}
}


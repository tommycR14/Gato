#include "grafico.h"
grafico::grafico() {
	window = new sf::RenderWindow(sf::VideoMode(1200, 900), "TIC - TAC - TOE");

	espadaT.loadFromFile("imagenes/espada.png");
	espadaS.setTexture(espadaT);

	escudoT.loadFromFile("imagenes/escudo.png");
	escudoS.setTexture(escudoT);

	gatoT.loadFromFile("imagenes/gato.png");
	gatoS.setTexture(gatoT);

	paisajeT.loadFromFile("imagenes/paisaje.jpg");
	paisajeS.setTexture(paisajeT);
	gatoS.setPosition(100, 40);
	paisajeS.setPosition(0, 0);
}

void grafico::eventos() {

	while (window->pollEvent(evento))
	{
		switch (evento.type) {
		case sf::Event::Closed:
			window->close();
			exit(1);
			break;
		}
	}
}
void grafico::draw(std::vector<std::vector<char>>& tab) {
	int x = 130, y = 100;
	eventos();
	window->clear();
	window->draw(paisajeS);
	window->draw(gatoS);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (tab[i][j] == 'x') {
				espadaS.setPosition(x,y);
				window->draw(espadaS);
				x += 340;
			}
			else if (tab[i][j] == 'o') {
				escudoS.setPosition(x, y);
				window->draw(escudoS);
				x += 340;
			}
			else if (tab[i][j] == ' ') 
				x += 340;
		}
		x = 130;
		y += 290;
	}
	window->display();
}


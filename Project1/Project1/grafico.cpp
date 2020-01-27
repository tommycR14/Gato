#include "grafico.h"

grafico::grafico() {
	window = new sf::RenderWindow(sf::VideoMode(1200, 950), "TIC - TAC - TOE");

	espadaT.loadFromFile("imagenes/espada.png");
	espadaS.setTexture(espadaT);

	escudoT.loadFromFile("imagenes/escudo.png");
	escudoS.setTexture(escudoT);

	gatoT.loadFromFile("imagenes/gato.png");
	gatoS.setTexture(gatoT);

	paisajeT.loadFromFile("imagenes/paisaje.jpg");
	paisajeS.setTexture(paisajeT);
	
	menuT.loadFromFile("imagenes/paisaje.jpg");
	menuS.setTexture(menuT);

	marcoT.loadFromFile("imagenes/marco.png");
	marcoS.setTexture(marcoT);
	marcoS.setPosition(87, 53);
	marcoT.loadFromFile("imagenes/marco.png");
	marcoS.setTexture(marcoT);
	gatoS.setPosition(80, 50);
	paisajeS.setPosition(0, 0);




}


void grafico::setMarcoS(int x, int y) {
	this->marcoS.setPosition(x,y);
}

void grafico::drawTablero(std::vector<std::vector<char>>& tab) {
	int x = 130, y = 84;
	window->clear();
	window->draw(paisajeS);
	window->draw(gatoS);
	window->draw(marcoS);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (tab[i][j] == 'x') {
				espadaS.setPosition(x, y);
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


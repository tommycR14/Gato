#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class grafico
{
private: 
	sf::RenderWindow* window;
	//Texturas
	sf::Texture paisajeT;
	sf::Texture espadaT;
	sf::Texture escudoT;
	sf::Texture gatoT;
	sf::Texture menuT;
	sf::Texture marcoT;
	sf::Texture texturaEspada;
	sf::Texture win;
	sf::Texture escudoTextura;
	//sprites
	sf::Sprite espadaS;
	sf::Sprite paisajeS;
	sf::Sprite escudoS;
	sf::Sprite gatoS;
	sf::Sprite menuS;
	sf::Sprite marcoS;
	sf::Sprite imagenEspada;
	sf::Sprite winS;
	sf::Sprite Iespada;
	sf::Sprite escudoSprite;
	//lestras
	sf::Font fuente;
	sf::Text texto;
	sf::Text texto3;



	//sonidos
	sf::SoundBuffer espadaB;
	sf::Sound espadaSound;

	sf::SoundBuffer golpeB;
	sf::Sound golpeS;

	sf::SoundBuffer lataB;
	sf::Sound lataS;
	sf::SoundBuffer vacioB;
	sf::Sound vacioS;


public: 
	grafico();
	~grafico() { delete window; }
	void drawTablero(std::vector<std::vector<char>>&);
	sf::RenderWindow*& getWindow() { return window; }
	void setMarcoS(int x,int y);
	void dibujaGanarEspadas();
	void dibujaGanarEscudos();
	void dibujaGanarEmpate();


	void dibujoGaneEspada();
	void dibujoGaneEscudo();
	void dibujoGaneEmpate();


};


#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class grafico
{
private: 
	sf::RenderWindow* window;

	sf::Texture paisajeT;
	sf::Sprite paisajeS;
	
	sf::Texture espadaT;
	sf::Sprite espadaS;
	
	sf::Texture escudoT;
	sf::Sprite escudoS;
	
	sf::Texture gatoT;
	sf::Sprite gatoS;
	

	sf::Texture menuT;
	sf::Sprite menuS;

	sf::Texture marcoT;
	sf::Sprite marcoS;



public: 
	grafico();
	~grafico() { delete window; }

	void drawTablero(std::vector<std::vector<char>>&);
	sf::RenderWindow*& getWindow() { return window; }
	void setMarcoS(int x,int y);
};


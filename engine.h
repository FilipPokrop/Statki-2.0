#include "pole.h"
#pragma once

class Engine
{

	sf::RenderWindow *window;
	sf::Font *font;
	sf::Text text;
	sf::Text info;
	sf::Text point[2];


Pole pole[10][10];
    Pole pole_przec[10][10];


    enum Game{MARK,SHOT,OVER};
    Game state;
	void update();
	void draw();
	int mark=0;
	void IAmark();
	void IAshot();
	int points=0,IApoints=0;


	public:



    Engine(sf::RenderWindow &win, sf::Font &fon);
    ~Engine();

    void runEngine();

};

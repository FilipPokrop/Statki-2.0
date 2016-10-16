#include <SFML/Graphics.hpp>
#pragma once

class Pole: public sf::Drawable,
	sf::Transformable
{

    bool ship; //oznacza czy jest statek
    bool shot; //oznacza czy pole by³o zaznaczone
    int height,width,marginX,marginY,size_=48;//wyokoœæ i szerokoœæ i margines
    bool IA;

    public:

    Pole(int=0,int=0,bool=false,bool=0,bool=0);
    ~Pole();




    void setPosition(int,int,int,int);//ustawia pozycjê pola

    bool getShip();//sprawdza czy jest statek
    bool getShot();//sprawdza czy bylo trafienie
    bool getBounds(sf::Vector2f &m);

    void setShot(bool);//zmienia wartość shot
    void setShip(bool);//zmienia wartość ship
    void setIA(bool);

    void update();
    void drawShot();
    void drawShip();
    void drawHit();

    sf::RectangleShape shape;
    sf::CircleShape circle;
    sf::RectangleShape cross[2];


    virtual void draw(sf::RenderTarget &target,sf::RenderStates states) const;
};

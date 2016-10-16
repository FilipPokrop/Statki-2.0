#include "pole.h"

using namespace sf;

Pole::Pole(int w,int h,bool sp,bool st,bool i)
{
    width=w;
    height=h;
    ship=sp;
    shot=st;
    IA=i;


//rysowaniepola

    shape.setSize(Vector2f(size_,size_));
    shape.setFillColor(Color(0,128,255));
    shape.setOutlineThickness(1);
    shape.setOutlineColor(Color::Black);
}

Pole::~Pole()
{
}
void Pole::setPosition(int x,int y,int mx,int my)
{
    width=x;
    height=y;
    marginX=mx;
    marginY=my;
}

bool Pole::getShip()
{
    return ship;
}

bool Pole::getShot()
{
    return shot;
}

void Pole::update()
{
    shape.setPosition(marginX+width*(size_+1),marginY+height*(size_+1));


     if(shot&&ship)
       {
      Pole::drawShip();
     drawHit();

    }



    else if(ship==true&&IA==false)
    {
      Pole::drawShip();

    }
    else if(shot==true)
        Pole::drawShot();


}

void Pole::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(shape);
    target.draw(circle);
    target.draw(cross[0]);
    target.draw(cross[1]);
}

void Pole::drawShip()
{

    circle.setRadius(size_/4);
    circle.setOrigin(size_/4,size_/4);
    circle.setPosition(marginX+size_/2+width*(size_+1),marginY+size_/2+height*(size_+1));
    circle.setOutlineThickness(size_/8);
    circle.setOutlineColor(Color::Red);
    circle.setFillColor(Color(0,128,255));

}

void Pole::drawShot()
{
    for(int i=0;i<2;i++)
    {
        cross[i].setSize(Vector2f(5,size_));
        cross[i].setOrigin(3,size_/2);
        cross[i].setFillColor(Color::Red);
        cross[i].setPosition(marginX+size_/2+width*(size_+1),marginY+size_/2+height*(size_+1));
    }
    cross[0].setRotation(45);
    cross[1].setRotation(135);
}

void Pole::drawHit()
{
    circle.setFillColor(Color::Red);
}

void Pole::setShot(bool s)
{
    shot=s;
}

void Pole::setShip(bool s)
{
    ship=s;
}

bool Pole::getBounds(Vector2f &m)
{
    return shape.getGlobalBounds().contains(m);
}
 void Pole::setIA(bool i)
 {
     IA=i;
 }

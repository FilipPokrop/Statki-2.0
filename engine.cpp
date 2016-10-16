#include "engine.h"
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <cstdio>


using namespace sf;

Engine::Engine(sf::RenderWindow &win, sf::Font &fon)
{
    window = &win;
    font=&fon;





    text.setFont(*font);
    text.setCharacterSize(240);
    text.setColor(Color::Black);
    info.setFont(*font);
    info.setColor(Color::Black);
    info.setCharacterSize(35);
    info.setString("Press ESC");
    info.setPosition(1280/2-info.getGlobalBounds().width/2,720/2-info.getGlobalBounds().height/2+150);
    /*
    for(int i=0; i<2; i++)
    {
        point[i].setFont(font);
        point[i].setColor(Color::Black);
        point[i].setCharacterSize(35);
    }
    point[0].setPosition(460,680);
    point[1].setPosition(840,680);
    */


    for(int x=0; x<10; x++)
    {
        for(int y=0; y<10; y++)
        {
            pole[x][y].setPosition(x,y,100,100);
            pole_przec[x][y].setPosition(x,y,680,100);
            pole_przec[x][y].setIA(true);
        }
    }
}


Engine::~Engine()
{
}

void Engine::runEngine()
{
    bool menu=false;
    state=MARK;
    IAmark();



    while(!menu)
    {
        if(IApoints>19&&points>19)
        {
            state=OVER;
            text.setString("DRAW");

        }
        else if(IApoints>19)
        {
            state=OVER;
            text.setString("LOSE");
        }
        else if(points>19)
        {
            state=OVER;
            text.setString("WIN");
        }


        Event event;
        Vector2f mouse(Mouse::getPosition(*window));

        while(window->pollEvent(event));
        {
            if (Keyboard::isKeyPressed(Keyboard::Escape))

                menu=true;

                if (event.type == sf::Event::Closed)
                window->close();



            for(int x=0; x<10; x++)
            {
                for(int y=0; y<10; y++)
                {
                    if(pole_przec[x][y].getBounds(mouse) && state==SHOT && pole_przec[x][y].getShot()==false &&
                            (event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left ))
                    {
                        pole_przec[x][y].setShot(true);
                        if(pole_przec[x][y].getShip()==false||points>19)
                            IAshot();
                        else points++;



                    }
                }
            }
            for(int x=0; x<10; x++)
            {
                for(int y=0; y<10; y++)
                {
                    if(pole[x][y].getBounds(mouse) && state==MARK && pole[x][y].getShip()==false &&
                            (event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left ))
                    {
                        pole[x][y].setShip(true);
                        mark++;
                        if(mark>=20)
                            state=SHOT;

                    }
                }
            }


        }
        update();
        draw();
    }


}

void Engine::draw()
{

    window->clear(Color::White);
    if(state!=OVER)
        for(int x=0; x<10; x++)
        {
            for(int y=0; y<10; y++)
            {
                window->draw(pole[x][y]);
                window->draw(pole_przec[x][y]);
            }
        }
    if(state==OVER)
    {
        text.setPosition(1280/2-text.getGlobalBounds().width/2,720/2-text.getGlobalBounds().height/2-100);
    window->draw(text);
    window->draw(info);
    }


    window->display();
}

void Engine::update()
{
    for(int x=0; x<10; x++)
    {
        for(int y=0; y<10; y++)
        {
            pole[x][y].update();
            pole_przec[x][y].update();
        }
    }

    //point[0].setString(points);
    //point[1].setString(IAppoints);
}

void Engine::IAmark()
{
    int x,y;
    srand( time( NULL ) );
    for(int i=0; i<20; i++)
    {
        do
        {
            x=rand()%10;
            y=rand()%10;
        }
        while(pole_przec[x][y].getShip()==true);

        pole_przec[x][y].setShip(true);




    }
}

void Engine::IAshot()
{
    int x,y;
    srand( time( NULL ) );

    do
    {
        x=rand()%10;
        y=rand()%10;
    }
    while(pole[x][y].getShot()==true);

    pole[x][y].setShot(true);
    if(pole[x][y].getShip()==true&&IApoints<20)
    {
        IApoints++;
        IAshot();
    }



    Sleep(100);





}

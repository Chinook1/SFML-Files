#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp> //add for sound
#include <cstdlib> //add for random
#include <ctime>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    sf::CircleShape shape(20.f);
    sf::RectangleShape rectShape(sf::Vector2f(100, 20)); //Rectangle shape
    sf::Vector2f position;//create position to record ball's position
    sf::Vector2f rectPos;//Create position to record rectangle's position
    int flag = 33; //a Flag
    double xval = .1, yval = .1; 
    srand(time(NULL));//add for random
    sf::SoundBuffer buffer; //add for sound
    if(!buffer.loadFromFile("4808.wav")) //add for sound
       return -1; //add for sound
    sf::Sound sound; //add for sound
    sound.setBuffer(buffer);//add for sound

    sf::Music music;
    if(!music.openFromFile("rach.ogg"))
        return -1;
    music.play();
    //music.setLoop(true); //Make the music loop
    
    shape.move(30,30);//Move circle closer to middle
    shape.setFillColor(sf::Color::Green);
    
    rectShape.setFillColor(sf::Color::Blue);
    rectShape.move(200, 480);
cout << position.x << ", " << position.y << endl;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
        }

        
        rectPos = rectShape.getPosition();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                if(rectPos.x > 0)
                    rectShape.move((-.25),0);
            }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                if((rectPos.x+100) < 500)
                    rectShape.move((.25),0);
            }

        


        position = shape.getPosition(); //get position
        
        
        if((position.x + (xval)) > 450)
            {
                xval = -.1 - ((rand()%10)/100.0);
                sound.play();
            }

        if((position.x + (xval)) < 0)
            {
                xval = .1+((rand()%10)/100.0);
                sound.play();
            }

        if((position.y + (yval)) > 450)
            {
                yval = -.1 - ((rand()%10)/100.0);
                sound.play();
            }

        if((position.y + (yval)) < 0)
            {
                yval = .1 + ((rand()%10)/100.0);
                sound.play();
            }
        shape.move(xval, yval);
        
        /*if(((position.x+20) > rectPos.x && (position.x + 20) < (rectPos.x+100)) && (position.y +20) >=450)
            ;*/
        if(((position.x+20) < rectPos.x || (position.x + 20) > (rectPos.x+100)) && (position.y +20) >=450)
            {
                cout << "You Lose!" << endl;
                music.stop();
                window.close();
            }

        window.clear();
        window.draw(shape);
        window.draw(rectShape);
        window.display();
    }
    music.stop();
    return 0;
}






#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <unistd.h>

int main() 
{
    srand((int)time(0));
    int x = (rand() % 800) + 0;
    int y = (rand() % 600) + 0;
    std::cout << "X: " << x << "\n";
    std::cout << "Y: " << y << "\n";
    sf::RenderWindow window(sf::VideoMode(800, 600), "Jogo mata mosca");
    window.setFramerateLimit(60);

    bool play = true;
    sf::Event event;

    // Images
    sf::Texture bg;
    if (bg.loadFromFile("data/images/bg.png") == -1) {
        return 1;
    }

    sf::Texture flyTexture;
    if(flyTexture.loadFromFile("data/images/mosquito.png") == -1) {
        return 1;
    }

    // Shapes
    // bg
    sf::RectangleShape rec;
    rec.setSize(sf::Vector2f(800, 600));
    rec.setPosition(0, 0);
    rec.setTexture(&bg);

    // Fly
    sf::RectangleShape fly;
    fly.setSize(sf::Vector2f(50, 50));
    fly.setPosition(x,y);
    fly.setTexture(&flyTexture);

    // game loop
    while(play == true) 
    {
        // Events
        while (window.pollEvent(event))
        {
            

            if(event.type == sf::Event::Closed) 
            {
                play = false;
            }
        }
    
        // Logic
        usleep(900000);
        int x = (rand() % 800) + 0;
        int y = (rand() % 600) + 0;
        x = (x < 0) ? 0 : x;
        y = (y < 0) ? 0 : y;
        std::cout << "X: " << x << "\n";
        std::cout << "Y: " << y << "\n";
        fly.setPosition(x, y);

        // Renderin
        window.clear();
        window.draw(rec);
        window.draw(fly);
        window.display();
    }

    return 0;
}
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

#include <SFML/Graphics.hpp>

#define WINDOW_STYLE_CLOSE 1 << 2

int main()
{
    const int WINDOW_WIDTH = 800, WINDOW_HEIGHT = 600;

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Color circles", WINDOW_STYLE_CLOSE);

    std::vector<sf::CircleShape> circles_list;
    srand(time(NULL));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
                break;
            case sf::Event::Closed:
                 window.close();
                 break;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    for (int i = 0; i < 3; i++)
                    {
                        sf::CircleShape circle(30.0f);
                        circle.setFillColor(sf::Color(sf::Uint8(rand() % 255), sf::Uint8(rand() % 255), sf::Uint8(rand() % 255)));                            // circle.setFillColor(sf::Color(sf::Uint8(rand() % 255), sf::Uint8(rand() % 255), sf::Uint8(rand() % 255), sf::Uint8(rand() % 255)));
                        sf::Vector2i mouse_position = sf::Mouse::getPosition(window); 
                        if (i == 0)
                        {
                            mouse_position.x += 15;
                            mouse_position.y += -20;
                        }
                        else if (i == 1)
                        {
                            mouse_position.x += -15;
                            mouse_position.y += -20;
                        }
                        else if (i == 2)
                        {
                            mouse_position.y += 20;
                        }

                        window.mapPixelToCoords(mouse_position);
                        circle.setPosition(sf::Vector2f(mouse_position));
                        circles_list.push_back(circle);
                    }
                }
                else if (event.mouseButton.button == sf::Mouse::Right)
                    circles_list.clear();
                break;
            }
        }

        window.clear(sf::Color::White);
        if (circles_list.size() >= 1)
        {
            for (int i = 0; i < circles_list.size(); i++)
            {
                window.draw(circles_list[i]);
            }
        }   
        window.display();
    }

    return 0;
}
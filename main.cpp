#include <SFML/Graphics.hpp>
#include "Game.hpp"

int main()
{
    Game game;

    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), GAME_NAME);

    window.setFramerateLimit(WIN_FRAMERATE);
    
    while (window.isOpen())
    {
        sf::Event event;
        //game.printToConsole(window); //INFO O MYSZCE

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return 0;
            }
        }

        window.clear();
        game.printMap(window);
        game.update(window);
        window.display();
    }

    return 0;
}

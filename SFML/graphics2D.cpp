#include <SFML/Graphics.hpp>
#include "Player.h"
#include "FrameRate.h"
#include "Enemy.h"
#include <iostream>

int main()
{
    /* INITIALIZE */
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML shapes", sf::Style::Default, sf::State::Windowed, settings);
    window.setFramerateLimit(60);
    /* END INITIALIZE */

    sf::Font font;
    if (!font.openFromFile("resources/fonts/arial.TTF")) {
        std::cerr << "Error loading font\n";
        return -1;
    }

    // Create FPS text
    

    Player player;
    Enemy enemy;
    FrameRate frameRate;

    /* INITIALIZE */
    player.Initialize();
    enemy.Initialize();
    frameRate.Initialize();
    /* END INITIALIZE */

    /* LOAD */
    player.Load();
    enemy.Load();
    frameRate.Load();
    /* END LOAD */

    sf::Clock clock;            // For delta time
    sf::Clock fpsClock;         // Separate clock for FPS calculation
    int frameCount = 0;         // Count frames for averaging

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        // Calculate delta time
        float deltaTime = clock.restart().asMilliseconds();

        // Update FPS counter every 0.5 seconds
        frameRate.Update();  // Much simpler now!

        /* UPDATE PLAYER POSITION */
        player.Update(enemy, deltaTime, window);
        enemy.Update(deltaTime);

        window.clear(sf::Color::Black);
        player.Draw(window);
        enemy.Draw(window);
        frameRate.Draw(window);   // Draw the FPS counter
        window.display();
    }
}
#pragma once
#include <SFML/Graphics.hpp>
class FrameRate
{
private:
    sf::Font font;
    float fps = 0.f;
    sf::Text fpsText;  // Change this to sf::Text instead of float
    sf::Clock fpsClock;     // Add clock as member variable
    int frameCount = 0;     // Add frame counter

public:
    FrameRate();  // ? Declare constructor
    void Draw(sf::RenderWindow& window);
    void Load();
    void Update();
    void Initialize();
};
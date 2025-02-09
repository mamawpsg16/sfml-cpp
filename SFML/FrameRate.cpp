#include "FrameRate.h"
#include <iostream>

FrameRate::FrameRate() :fpsText(font) {}

void FrameRate::Initialize()
{
    if (!font.openFromFile("resources/fonts/arial.TTF")) {
        std::cerr << "Error loading font\n";
    }
    fpsText.setFont(font);  // Set the font for the text
    fpsText.setCharacterSize(20);
    fpsText.setFillColor(sf::Color::Green);
    fpsText.setPosition(sf::Vector2f(10, 10));
}

void FrameRate::Draw(sf::RenderWindow& window)
{
    window.draw(fpsText);
}

void FrameRate::Load()
{
    // Any additional loading if needed
}

void FrameRate::Update()
{
    frameCount++;
    if (fpsClock.getElapsedTime().asSeconds() >= 0.5f) {
        float elapsedTime = fpsClock.getElapsedTime().asSeconds();
        fps = frameCount / elapsedTime;
        fpsText.setString("FPS: " + std::to_string(static_cast<int>(fps)));
        frameCount = 0;
        fpsClock.restart();
    }
}
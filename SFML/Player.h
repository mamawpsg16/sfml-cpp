#pragma once  // Add this to prevent multiple inclusions
#include <SFML/Graphics.hpp>

class Enemy;

class Player
{
private:
    sf::Texture m_texture;
    std::vector<sf::CircleShape> m_bullets;
    std::vector<sf::Vector2f> m_bulletDirections;

    float m_bulletSpeed = 0.5f;
    float m_playerSpeed = 1.0f;

    sf::RectangleShape boundingRectangle;

    //sf::Vector2i spriteSize = { 64, 64 };
    sf::Vector2i spriteSize;
    sf::Vector2f spriteMovementSpeed;

    sf::Clock shootClock;      // Timer for shooting cooldown
    float shootCooldown = 200.0f;  // Cooldown in milliseconds (0.2 seconds)
    bool canShoot = true;      // Flag to track if player can shoot

public:
    sf::Sprite m_sprite; // Allows deferred initialization

public:
    Player();  // ✅ Declare constructor
    void Draw(sf::RenderWindow& window);
    void Load();
    void Update(Enemy& enemy, float deltaTime, sf::RenderWindow& window);
    void Initialize();
};

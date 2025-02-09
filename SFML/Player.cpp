#include "Player.h"
#include "Enemy.h"
#include "Math.h"
#include <iostream>


// ✅ Properly initialize sf::Sprite using m_texture
Player::Player() : m_sprite(m_texture) {}

void Player::Initialize()
{

	spriteSize = sf::Vector2i(64, 64);
	spriteMovementSpeed = sf::Vector2f(1.0f, 0.0f);

	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Red);
	boundingRectangle.setOutlineThickness(2.0f);
}


void Player::Draw(sf::RenderWindow& window)
{
    // Draws the player's sprite on the window
    window.draw(m_sprite);

    // Draws the player's bounding rectangle (for debugging collisions)
    window.draw(boundingRectangle);

    // Loops through all active bullets and draws each at its current position
    for (size_t i = 0; i < m_bullets.size(); i++)
    {
        window.draw(m_bullets[i]); // Draws each bullet at its updated position
    }
}


void Player::Load()
{
    if (!m_texture.loadFromFile("resources/player/textures/skeleton_spritesheet.png"))
    {
        std::cerr << "Error Player Texture: Could not load!" << std::endl;
    }

    // ✅ Lazily create the sprite
    m_sprite = sf::Sprite(m_texture);

    int xIndex = 0;
    int yIndex = 0;

    m_sprite.setTextureRect(sf::IntRect({ xIndex * spriteSize.x, yIndex * spriteSize.y }, { spriteSize.x , spriteSize.y }));
    m_sprite.setPosition(sf::Vector2f(200, 200));
	m_sprite.scale(sf::Vector2f({ 2.0f, 2.0f }));

	boundingRectangle.setSize(sf::Vector2f(sf::Vector2f(spriteSize.x * m_sprite.getScale().x, spriteSize.y * m_sprite.getScale().y)));
}

void Player::Update(Enemy& enemy, float deltaTime, sf::RenderWindow& window)
{
	sf::Vector2f position = m_sprite.getPosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		m_sprite.setPosition(position + sf::Vector2f(spriteMovementSpeed.x, spriteMovementSpeed.y) * m_playerSpeed * deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		m_sprite.setPosition(position - sf::Vector2f(spriteMovementSpeed.x, spriteMovementSpeed.y) * m_playerSpeed * deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		m_sprite.setPosition(position - sf::Vector2f(spriteMovementSpeed.y, spriteMovementSpeed.x) * m_playerSpeed * deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		m_sprite.setPosition(position + sf::Vector2f(spriteMovementSpeed.y, spriteMovementSpeed.x) * m_playerSpeed * deltaTime);
	}

    // Check if enough time has passed since last shot
    if (shootClock.getElapsedTime().asMilliseconds() >= shootCooldown) {
        canShoot = true;
    }

    // Shooting logic with cooldown
    if (const auto shoot = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && canShoot) {

        // Get the mouse position relative to the window
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        // Convert to world coordinates
        sf::Vector2f worldPos = window.mapPixelToCoords(mousePos); 

        // Create a bullet
        sf::CircleShape bullet(5);
        bullet.setPosition(m_sprite.getPosition()); // Start from player position
        bullet.setFillColor(sf::Color::Red); // Just for visibility

        // Calculate bullet direction
        sf::Vector2f direction = Math::NormalizedVector(worldPos - m_sprite.getPosition());

        // Store bullet with its direction
        m_bullets.emplace_back(bullet);
        m_bulletDirections.emplace_back(direction); // Store direction separately

        // Reset the shooting cooldown
        shootClock.restart();
        canShoot = false;
    }

    // Move bullets and check for collisions
    for (int i = m_bullets.size() - 1; i >= 0; i--) // Loop in reverse
    {
        // Move the bullet
        m_bullets[i].move(m_bulletDirections[i] * m_bulletSpeed * deltaTime);

        // Check if bullet collides with enemy
       
        if (m_bullets[i].getGlobalBounds().findIntersection(enemy.m_sprite.getGlobalBounds()).has_value())
        {
            // Remove bullet and its direction from the vectors
            m_bullets.erase(m_bullets.begin() + i);
            m_bulletDirections.erase(m_bulletDirections.begin() + i);
        }
    }

    boundingRectangle.setPosition(m_sprite.getPosition());
    if (Math::DidRectCollide(m_sprite.getGlobalBounds(), enemy.m_sprite.getGlobalBounds())) {
        std::cout << "SPRITES COLID" << '\n';
    }
	
}


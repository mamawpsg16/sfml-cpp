#include "Enemy.h"
#include <iostream>

Enemy::Enemy() :m_sprite(m_texture) {}

void Enemy::Initialize() {
	spriteSize = sf::Vector2i(64, 64);
	spriteMovementSpeed = sf::Vector2f(1.5f, 0.0f);

	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Blue);
	boundingRectangle.setOutlineThickness(2.0f);
}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
	window.draw(boundingRectangle);
}

void Enemy::Load() {

	if (!m_texture.loadFromFile("resources/player/textures/skeleton_spritesheet.png"))
	{
		std::cerr << "Error Enemy Texture: Could not load!" << std::endl;
	}
	m_sprite = sf::Sprite(m_texture);

	// Set the texture rectangle (X, Y, WIDTH, HEIGHT)
	int xEnemyIndex = 0;
	int yEnemyIndex = 2;
	m_sprite.setTextureRect(sf::IntRect({ xEnemyIndex * 1, yEnemyIndex * spriteSize.y }, { spriteSize.x, spriteSize.y }));
	m_sprite.setPosition(sf::Vector2f(200.0, 250.0f));
	m_sprite.scale(sf::Vector2f({ 2.0f, 2.0f }));

	boundingRectangle.setSize(sf::Vector2f(sf::Vector2f(spriteSize.x * m_sprite.getScale().x, spriteSize.y * m_sprite.getScale().y)));

}

void Enemy::Update(float deltaTime) {
	boundingRectangle.setPosition(m_sprite.getPosition());
}


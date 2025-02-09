#include <SFML/Graphics.hpp>
#include <optional> // Required for std::optional

class Enemy
{
private:
    sf::Texture m_texture;

    sf::RectangleShape boundingRectangle;

    sf::Vector2i spriteSize;
    sf::Vector2f spriteMovementSpeed;
public:
    sf::Sprite m_sprite; // Allows deferred initialization

public:
    Enemy();  // ✅ Declare constructor
    void Draw(sf::RenderWindow& window);
    void Load();
    void Update(float deltaTime);
    void Initialize();
};

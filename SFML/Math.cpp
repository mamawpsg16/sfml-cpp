#include "Math.h"

sf::Vector2f Math::NormalizedVector(const sf::Vector2f& vector) {
	float m = std::sqrt((vector.x * vector.x) + (vector.y * vector.y));

	sf::Vector2f normalizedVector;
	normalizedVector.x = vector.x / m;
	normalizedVector.y = vector.y / m;

	return normalizedVector;
}

bool Math::DidRectCollide(sf::FloatRect rect1, sf::FloatRect rect2)
{
	return rect1.findIntersection(rect2).has_value();
}

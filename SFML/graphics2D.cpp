#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

sf::Vector2f NormalizedVector(const sf::Vector2f& vector) {
	float m = std::sqrt((vector.x * vector.x) + (vector.y * vector.y));

	sf::Vector2f normalizedVector;
	normalizedVector.x = vector.x / m;
	normalizedVector.y = vector.y / m;

	return normalizedVector;
}

int main()
{
	// create the window
	sf::ContextSettings settings;
	settings.antiAliasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "SFML shapes", sf::Style::Default, sf::State::Windowed, settings);

	//std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;

	std::vector<sf::RectangleShape> bullets;
	float bulletSpeed = 1.0f;

	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("resources/player/textures/skeleton_spritesheet.png"))
	{
		std::cerr << "Error: Could not load texture!" << std::endl;
		return -1;
	}

	// ✅ Declare and initialize the sprite after texture is loaded
	sf::Sprite playerSprite(playerTexture);
	// Set the texture rectangle (X, Y, WIDTH, HEIGHT)
	int xIndex = 0;
	int yIndex = 0;
	playerSprite.setTextureRect(sf::IntRect({ xIndex * 64, yIndex * 64 }, { 64, 64 }));
	playerSprite.scale(sf::Vector2f({ 2.0f, 2.0f }));

	

	sf::Texture enemyTexture;
	if (!enemyTexture.loadFromFile("resources/player/textures/skeleton_spritesheet.png"))
	{
		std::cerr << "Error: Could not load texture!" << std::endl;
		return -1;
	}
	sf::Sprite enemySprite(enemyTexture);
	// Set the texture rectangle (X, Y, WIDTH, HEIGHT)
	int xEnemyIndex = 0;
	int yEnemyIndex = 2;
	enemySprite.setTextureRect(sf::IntRect({ xEnemyIndex * 64, yEnemyIndex * 64 }, { 64, 64 }));
	enemySprite.scale(sf::Vector2f({ 2.0f, 2.0f }));
	enemySprite.setPosition(sf::Vector2f(200.0, 250.0f));

	//sf::Vector2f bulletDirection = enemySprite.getPosition() - bullets.getPosition();
	//bulletDirection = NormalizedVector(bulletDirection);
	
	



		//sf::Texture texture;
		//if (!texture.loadFromFile("image.png", false, sf::IntRect({ 10, 10 }, { 32, 32 })))
		//{
		//    // error...
		//}

		sf::CircleShape shape(50.f);
	//shape.setFillColor(sf::Color::Cyan);
	shape.setPosition(sf::Vector2f(100, 100));
	shape.setOutlineThickness(10);
	shape.setOutlineColor(sf::Color::Transparent);

	//shape.setTexture(&texture); // texture is a sf::Texture
	//shape.setTextureRect(sf::IntRect({ 10, 10 }, { 100, 100 }));
	// change the number of sides (points) to 100
	//shape.setPointCount(100);
	// run the program as long as the window is open
	sf::CircleShape triangle(80.f, 3);
	triangle.setPosition(sf::Vector2f(201, 100));
	// define a square
	sf::CircleShape square(80.f, 4);
	square.setPosition(sf::Vector2f(361, 100));

	// define an octagon
	sf::CircleShape octagon(80.f, 8);
	octagon.setPosition(sf::Vector2f(521, 100));

	// define a 120x50 rectangle
	sf::RectangleShape rectangle({ 120.f, 50.f });

	// change the size to 100x100
	rectangle.setSize({ 100.f, 100.f });
	rectangle.setPosition(sf::Vector2f(680, 100));

	// create an empty shape
	sf::ConvexShape convex;

	// resize it to 5 points
	convex.setPointCount(5);

	// define the points
	convex.setPoint(0, { 0.f, 0.f });
	convex.setPoint(1, { 150.f, 10.f });
	convex.setPoint(2, { 120.f, 90.f });
	convex.setPoint(3, { 30.f, 100.f });
	convex.setPoint(4, { 0.f, 50.f });

	sf::RectangleShape line({ 150.f, 5.f });
	line.rotate(sf::degrees(45));
	line.setPosition(sf::Vector2f(100, 0));



	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		while (const std::optional event = window.pollEvent())
		{
			// "close requested" event: we close the window
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}
			/*else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
				if (keyPressed->scancode == sf::Keyboard::Scancode::D) {
					sf::Vector2f position = playerSprite.getPosition();
					std::cout << "X =" << position.x << "Y =" << position.y << '\n';
					playerSprite.setPosition(position + sf::Vector2f(1.0f, 0.0f));
				}
			}*/
		}
		sf::Vector2f position = playerSprite.getPosition();
		//bullet.setPosition(bullet.getPosition() + bulletDirection * bulletSpeed);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
			std::cout << "Moving Right\n"; // Moves as long as key is held
			std::cout << "X =" << position.x << "Y =" << position.y << '\n';
			playerSprite.setPosition(position + sf::Vector2f(1.0f, 0.0f));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
			std::cout << "Moving Left\n"; // Moves as long as key is held
			std::cout << "X =" << position.x << "Y =" << position.y << '\n';
			playerSprite.setPosition(position - sf::Vector2f(1.0f, 0.0f));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
			std::cout << "Moving Up\n"; // Moves as long as key is held
			std::cout << "X =" << position.x << "Y =" << position.y << '\n';
			playerSprite.setPosition(position - sf::Vector2f(0.0f, 1.0f));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
			std::cout << "Moving Down\n"; // Moves as long as key is held
			std::cout << "X =" << position.x << "Y =" << position.y << '\n';
			playerSprite.setPosition(position + sf::Vector2f(0.0f, 1.0f));
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			bullets.emplace_back(sf::RectangleShape(sf::Vector2f(20, 10)));
			int i = bullets.size() - 1;
			bullets[i].setPosition(playerSprite.getPosition());

		}

		for (size_t i = 0; i < bullets.size(); i++)
		{
			sf::Vector2f bulletDirection = enemySprite.getPosition() - bullets[i].getPosition();
			bulletDirection = NormalizedVector(bulletDirection);

			bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
		}

		//// clear the window with black color
		//window.clear(sf::Color::Black);


		//// draw everything here...
		window.clear(sf::Color::Black);

		/*    window.draw(shape);
			window.draw(triangle);
			window.draw(square);
			window.draw(octagon);
			window.draw(rectangle);
			window.draw(convex);
			window.draw(line);*/
		window.draw(enemySprite);
		window.draw(playerSprite);
		for (size_t i = 0; i < bullets.size(); i++)
		{
			window.draw(bullets[i]);
		}
		//// end the current frame
		window.display();
	}
}
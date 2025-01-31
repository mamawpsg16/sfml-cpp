#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	// create the window
	sf::ContextSettings settings;
	settings.antiAliasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML shapes", sf::Style::Default, sf::State::Windowed, settings);

	//std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;

	sf::Texture skeletonTexture;
	if (!skeletonTexture.loadFromFile("resources/player/textures/skeleton_spritesheet.png"))
		//if (!skeletonTexture.loadFromFile("../resources/player/textures/skeleton.png"))
	{
		std::cerr << "Error: Could not load texture!" << std::endl;
		int age;
		std::cin >> age;
		return -1;
	}

	// ✅ Declare and initialize the sprite after texture is loaded
	sf::Sprite skeletonSprite(skeletonTexture);

	// Set the texture rectangle (X, Y, WIDTH, HEIGHT)
	int xIndex = 0;
	int yIndex = 0;
	skeletonSprite.setTextureRect(sf::IntRect({ xIndex * 64, yIndex * 64 }, { 64, 64 }));
	skeletonSprite.scale(sf::Vector2f({ 2.0f, 2.0f }));



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
					sf::Vector2f position = skeletonSprite.getPosition();
					std::cout << "X =" << position.x << "Y =" << position.y << '\n';
					skeletonSprite.setPosition(position + sf::Vector2f(1.0f, 0.0f));
				}
			}*/
		}
		sf::Vector2f position = skeletonSprite.getPosition();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
			std::cout << "Moving Right\n"; // Moves as long as key is held
			std::cout << "X =" << position.x << "Y =" << position.y << '\n';
			skeletonSprite.setPosition(position + sf::Vector2f(1.0f, 0.0f));
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
			std::cout << "Moving Left\n"; // Moves as long as key is held
			std::cout << "X =" << position.x << "Y =" << position.y << '\n';
			skeletonSprite.setPosition(position - sf::Vector2f(1.0f, 0.0f));
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
			std::cout << "Moving Up\n"; // Moves as long as key is held
			std::cout << "X =" << position.x << "Y =" << position.y << '\n';
			skeletonSprite.setPosition(position - sf::Vector2f(0.0f, 1.0f));
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
			std::cout << "Moving Down\n"; // Moves as long as key is held
			std::cout << "X =" << position.x << "Y =" << position.y << '\n';
			skeletonSprite.setPosition(position + sf::Vector2f(0.0f, 1.0f));
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
		window.draw(skeletonSprite);
		//// end the current frame
		window.display();
	}
}
#include <SFML/Graphics.hpp>
#include <iostream>


//int main()
//{
//
//	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML works!", sf::Style::Default, sf::State::Windowed);
//
//	//// change the position of the window (relatively to the desktop)
//	//window.setPosition({ 50, 50 });
//
//	//// change the size of the window
//	//window.setSize({ 640, 480 });
//
//	//// change the title of the window
//	//window.setTitle("SFML window");
//
//	//// get the size of the window
//	//sf::Vector2u size = window.getSize();
//
//	//auto [width, height] = size;
//	//std::cout << "width = " << width << "height = " << height << '\n';
//
//	//// check whether the window has the focus
//	//bool focus = window.hasFocus();
//	//std::cout << "focus = " << focus << '\n';
//
//	// Never use both setVerticalSyncEnabled and setFramerateLimit at the same time! They would badly mix and make things worse.
//	window.setVerticalSyncEnabled(true); // call it once after creating the window
//	window.setFramerateLimit(60); // call it once after creating the window
//
//	sf::CircleShape shape(100.f);
//	shape.setFillColor(sf::Color::Green);
//
//	const auto onClose = [&window](const sf::Event::Closed&)
//	{
//		window.close();
//	};
//
//	const auto onKeyPressed = [&window](const sf::Event::KeyPressed& keyPressed)
//	{
//		if (keyPressed.scancode == sf::Keyboard::Scancode::Escape)
//			window.close();
//	};
//
//	const auto onKeyReleased = [&window](const sf::Event::KeyReleased& keyReleased)
//	{
//			std::cout << static_cast<int>(keyReleased.scancode)<< " Key Released";
//	};
//
//	const auto onResized = [&window](const sf::Event::Resized& resized)
//	{
//		std::cout << "New width: " << resized.size.x << std::endl;
//		std::cout << "New height: " << resized.size.y << std::endl;
//		// You can also perform additional actions here, like resizing the window's view:
//		//window.setView(sf::View(sf::FloatRect(0, 0, resized.size.x, resized.size.y)));
//	};
//
//	const auto onFocusLost = [&window](const sf::Event::FocusLost&) {
//		std::cout << "Focus Lost" << '\n';
//	};
//
//	const auto onFocusGained = [&window](const sf::Event::FocusGained&) {
//		std::cout << "Focus Gained" << '\n';
//	};
//
//	
//	const auto onTexEntered = [&window](const sf::Event::TextEntered& textEntered) {
//		std::cout << "Focus Gained" << '\n';
//		if (textEntered.unicode < 128)
//			std::cout << "ASCII character typed: " << static_cast<char>(textEntered.unicode) << std::endl;
//	};
//
//	const auto onMouseWheelScrolled = [&window](const sf::Event::MouseWheelScrolled& mouseWheelScrolled) {
//		switch (mouseWheelScrolled.wheel)
//		{
//		case sf::Mouse::Wheel::Vertical :
//			std::cout << "Wheel Type: Vertical" << '\n';
//			break;
//		case sf::Mouse::Wheel::Horizontal :
//			std::cout << "Wheel Type: Horizontal" << '\n';
//			break;
//		}
//		std::cout << "wheel movement: " << mouseWheelScrolled.delta << std::endl;
//		std::cout << "mouse x: " << mouseWheelScrolled.position.x << std::endl;
//		std::cout << "mouse y: " << mouseWheelScrolled.position.y << std::endl;
//	};
//
//	const auto onMouseButtonPressed = [&window](const sf::Event::MouseButtonPressed& mouseButtonPressed) {
//		if (mouseButtonPressed.button == sf::Mouse::Button::Right)
//		{
//			std::cout << "the right button was pressed" << std::endl;
//			std::cout << "mouse x: " << mouseButtonPressed.position.x << std::endl;
//			std::cout << "mouse y: " << mouseButtonPressed.position.y << std::endl;
//		}
//		else if (mouseButtonPressed.button == sf::Mouse::Button::Left)
//		{
//			std::cout << "the left button was pressed" << std::endl;
//			std::cout << "mouse x: " << mouseButtonPressed.position.x << std::endl;
//			std::cout << "mouse y: " << mouseButtonPressed.position.y << std::endl;
//		}
//		else if (mouseButtonPressed.button == sf::Mouse::Button::Middle)
//		{
//			std::cout << "the left button was pressed" << std::endl;
//			std::cout << "mouse x: " << mouseButtonPressed.position.x << std::endl;
//			std::cout << "mouse y: " << mouseButtonPressed.position.y << std::endl;
//		}
//	};
//
//	const auto onMouseEnteredWindow = [&window](const sf::Event::MouseEntered&) {
//		std::cout << "the mouse cursor has entered the window" << std::endl;
//	};
//
//	const auto onMouseLeftWindow = [&window](const sf::Event::MouseLeft&) {
//		std::cout << "the mouse cursor has left the window" << std::endl;
//	};
//
//
//	//  To disable repeated KeyPressed events
//	window.setKeyRepeatEnabled(false);
//
//	// set the mouse position globally (relative to the desktop)
//	//sf::Mouse::setPosition({ 10, 50 });
//
//	// set the mouse position locally (relative to a window)
//	//sf::Mouse::setPosition({ 10, 50 }, window); // window is a sf::Window
//
//	// run the program as long as the window is open
//	while (window.isOpen())
//	{
//		/** EVENTS */
//
//		//SECOND WAY OF HANDLING EVENTS
//		//window.handleEvents(onClose, onKeyPressed, onKeyReleased, onResized, onFocusLost, onFocusGained, onTexEntered, onMouseWheelScrolled, onMouseEnteredWindow, onMouseLeftWindow);
//
//		//FIRST WAY OF HANDLING EVENTS
//		// check all the window's events that were triggered since the last iteration of the loop
//		while (const std::optional event = window.pollEvent())
//		{
//			if (event->is<sf::Event::Closed>()) {
//				window.close(); // close window
//			}
//			else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
//			{
//
//				// keyPressed->scancode can be a 37 or anything based on what the user press in keyboard
//				// keyPressed->scancode
//
//		//	// Output the scancode as an integer
//				std::cout << "Scancode: " << static_cast<int>(keyPressed->scancode) << std::endl;
//
//
//			// sf::Keyboard::Scancode::Escape = 37
//				if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
//					window.close();
//			}
//			else if (const auto* keyPressed = event->getIf<sf::Event::KeyReleased>())
//			{
//
//				// keyPressed->scancode can be a 37 or anything based on what the user press in keyboard
//				// keyPressed->scancode
//
//		//	// Output the scancode as an integer
//				std::cout << "Scancode: Keyreleased " << static_cast<int>(keyPressed->scancode) << std::endl;
//
//			}
//			else if (const auto* resized = event->getIf<sf::Event::Resized>())
//			{
//				std::cout << "new width: " << resized->size.x << std::endl;
//				std::cout << "new height: " << resized->size.y << std::endl;
//			}else if (const auto* onFocusLost = event->getIf<sf::Event::FocusLost>())
//			{
//				std::cout << "Focus Lost" << '\n';
//			}else if (const auto* onFocusGained = event->getIf<sf::Event::FocusGained>())
//			{
//				std::cout << "Focus Gained" << '\n';
//			}else if (const auto* textEntered = event->getIf<sf::Event::TextEntered>())
//			{
//				if (textEntered->unicode < 128)
//					std::cout << "ASCII character typed: " << static_cast<char>(textEntered->unicode) << std::endl;
//
//			}else if (const auto* mouseWheelScrolled = event->getIf<sf::Event::MouseWheelScrolled>())
//			{
//				switch (mouseWheelScrolled->wheel)
//				{
//				case sf::Mouse::Wheel::Vertical:
//					std::cout << "wheel type: vertical" << std::endl;
//					break;
//				case sf::Mouse::Wheel::Horizontal:
//					std::cout << "wheel type: horizontal" << std::endl;
//					break;
//				}
//				std::cout << "wheel movement: " << mouseWheelScrolled->delta << std::endl;
//				std::cout << "mouse x: " << mouseWheelScrolled->position.x << std::endl;
//				std::cout << "mouse y: " << mouseWheelScrolled->position.y << std::endl;
//			}
//			//else if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
//			//{
//			//	if (mouseButtonPressed->button == sf::Mouse::Button::Right)
//			//	{
//			//		std::cout << "the right button was pressed" << std::endl;
//			//		std::cout << "mouse x: " << mouseButtonPressed->position.x << std::endl;
//			//		std::cout << "mouse y: " << mouseButtonPressed->position.y << std::endl;
//			//	}else if (mouseButtonPressed->button == sf::Mouse::Button::Left)
//			//	{
//			//		std::cout << "the left button was pressed" << std::endl;
//			//		std::cout << "mouse x: " << mouseButtonPressed->position.x << std::endl;
//			//		std::cout << "mouse y: " << mouseButtonPressed->position.y << std::endl;
//			//	}else if (mouseButtonPressed->button == sf::Mouse::Button::Middle)
//			//	{
//			//		std::cout << "the left button was pressed" << std::endl;
//			//		std::cout << "mouse x: " << mouseButtonPressed->position.x << std::endl;
//			//		std::cout << "mouse y: " << mouseButtonPressed->position.y << std::endl;
//			//	}
//			//}
//			//else if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>())
//			//{
//			//	std::cout << "new mouse x: " << mouseMoved->position.x << std::endl;
//			//	std::cout << "new mouse y: " << mouseMoved->position.y << std::endl;
//			//}
//			//else if (const auto* mouseMovedRaw = event->getIf<sf::Event::MouseMovedRaw>())
//			//{
//			//	std::cout << "new mouse raw x: " << mouseMovedRaw->delta.x << std::endl;
//			//	std::cout << "new mouse raw y: " << mouseMovedRaw->delta.y << std::endl;
//			//}
//			else if (event->is<sf::Event::MouseEntered>()) {
//				std::cout << "the mouse cursor has entered the window" << std::endl;
//			}
//			else if (event->is<sf::Event::MouseLeft>()) {
//				std::cout << "the mouse cursor has left the window" << std::endl;
//			}
//		}
//
//		/** END OF EVENTS */
//
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
//		{
//			std::cout << "LEFT SCANCODE" << static_cast<int>(sf::Keyboard::Scancode::Right) << '\n';
//			std::cout << "Left Key Pressed" << '\n';
//		}
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right))
//		{
//			std::cout << "RIGHT SCANCODE" << static_cast<int>(sf::Keyboard::Scancode::Right) << '\n';
//			std::cout << "Right Key Pressed" << '\n';
//		}
//
//
//		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
//		{
//			std::cout << "MOUSE BUTTON LEFT Pressed" << '\n';
//		}
//
//		// Get global mouse position (relative to the desktop)
//		sf::Vector2i globalPosition = sf::Mouse::getPosition();
//		std::cout << "GLOBAL POSITION: (" << globalPosition.x << ", " << globalPosition.y << ")\n";
//
//		// Get local mouse position (relative to the window)
//		sf::Vector2i localPosition = sf::Mouse::getPosition(window);
//		std::cout << "LOCAL POSITION: (" << localPosition.x << ", " << localPosition.y << ")\n";
//	}
//
//}
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

//int main()
//{
//    // create the window
//    sf::Window window(sf::VideoMode({ 800, 600 }), "OpenGL", sf::Style::Default);
//    window.setVerticalSyncEnabled(true);
//
//    // activate the window
//    window.setActive(true);
//
//    // load resources, initialize the OpenGL states, ...
//
//    // run the main loop
//    bool running = true;
//    while (running)
//    {
//        // handle events
//        while (const std::optional event = window.pollEvent())
//        {
//            if (event->is<sf::Event::Closed>())
//            {
//                // end the program
//                running = false;
//            }
//            else if (const auto* resized = event->getIf<sf::Event::Resized>())
//            {
//                // adjust the viewport when the window is resized
//                glViewport(0, 0, resized->size.x, resized->size.y);
//            }
//        }
//
//        // clear the buffers
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//        // draw...
//
//        // end the current frame (internally swaps the front and back buffers)
//        window.display();
//    }
//
//    // release resources...
//}
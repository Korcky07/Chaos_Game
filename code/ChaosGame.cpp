// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>

// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main()
{
    // Create a video mode object
	VideoMode vm(1920, 1080);
	// Create and open a window for the game
	RenderWindow window(vm, "Chaos Game!!", Style::Default);

    vector<Vector2f> vertices;
    vector<Vector2f> points;

    sf::Font font;
        if (!font.loadFromFile("ComicSans.ttf"))
        {
            throw runtime_error("Could not open file");
        }

        sf::Text text;

        bool nextMessage = false;

        text.setFont(font);

        text.setString("Hello! Welcome to the Chaos Game! Press Enter to start!");
        
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Cyan);

	while (window.isOpen())
	{
        /*
		****************************************
		Handle the players input
		****************************************
		*/

        if (nextMessage == true)
        {
            text.setString("Please pick a point from within the triangle.");
        }
        
      


        Event event;
		while (window.pollEvent(event))
		{
            if (event.type == Event::Closed)
            {
				// Quit the game when the window is closed
				window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed && nextMessage == true)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "the left button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;

                    if(vertices.size() < 3)
                    {
                        vertices.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
                    }
                    else if(points.size() == 0)
                    {
                        ///fourth click
                        ///push back to points vector
                    }
                }
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

        if (Keyboard::isKeyPressed(Keyboard::Enter))
        {
            nextMessage = true; 
        }
        /*
		****************************************
		Update
		****************************************
		*/

        if(points.size() > 0)
        {
            ///generate more point(s)
            ///select random vertex
            ///calculate midpoint between random vertex and the last point in the vector
            ///push back the newly generated coord.
        }

        /*
		****************************************
		Draw
		****************************************
		*/
        window.clear();
        window.draw(text);
        for(int i = 0; i < vertices.size(); i++)
        {
            
            RectangleShape rect(Vector2f(10,10));
            rect.setPosition(Vector2f(vertices[i].x, vertices[i].y));
            rect.setFillColor(Color::Cyan);
            window.draw(rect);
        }
        window.display();
    }
}
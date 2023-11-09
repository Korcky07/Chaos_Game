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
    vector<Color> colors;

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

        sf::Text count;

        count.setFont(font);

        count.setString("0");
        count.setPosition(1800, 980);

        count.setCharacterSize(50);
        count.setFillColor(sf::Color::Cyan);


        colors.push_back(sf::Color::Cyan);
        colors.push_back(sf::Color::Yellow);
        colors.push_back(sf::Color::Magenta);

	while (window.isOpen())
	{
        /*
		****************************************
		Handle the players input
		****************************************
		*/

        if (nextMessage == true)
        {
            text.setString("Please pick 3 spots to make a triangle");
        }
        
      


        Event event;
		while (window.pollEvent(event))
		{
            if (event.type == Event::Closed)
            {
				// Quit the game when the window is closed
				window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed && nextMessage)
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
                        points.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
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
            int vertex = rand() % 3;
            ///calculate midpoint between random vertex and the last point in the vector
            sf::Vector2f point;
            point.x = (vertices[vertex].x + points.back().x) / 2;
            point.y = (vertices[vertex].y + points.back().y) / 2;
            ///push back the newly generated coord.
            points.push_back(point);
        }

        for (int i = 0; )
        /*
		****************************************
		Draw
		****************************************
		*/
        window.clear();
        window.draw(text);
        count.setString(to_string(points.size()));
        window.draw(count);
        for(int i = 0; i < vertices.size(); i++)
        {
            RectangleShape rect(Vector2f(10,10));
            rect.setPosition(Vector2f(vertices[i].x, vertices[i].y));
            rect.setFillColor(Color::White);
            window.draw(rect);
        }
        int colorIndex = 0;
        for (int i = 0; i < points.size(); i++)
        {
            CircleShape point(5);
            point.setPosition(Vector2f(points[i].x, points[i].y));
            point.setFillColor(colors.at(colorIndex));
            window.draw(point);
            colorIndex++;
            if (colorIndex == colors.size())
            {
                colorIndex = 0;
            }
        }
        window.display();
    }
}
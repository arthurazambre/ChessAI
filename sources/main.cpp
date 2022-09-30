#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	bool is_selected = false;
    sf::RenderWindow window(sf::VideoMode(584, 584), "Chess");
    sf::RectangleShape shape;
	shape.setSize(sf::Vector2f(100, 100));
    shape.setFillColor(sf::Color::Red);
	shape.setOrigin(50.0f, 50.0f);

	sf::Font arial_font;
	if (!arial_font.loadFromFile("fonts/arial.ttf"))
		std::cout << "[ERROR] Could not load the arial font" << std::endl;

	sf::Text display("truc", arial_font, 50);
	display.setPosition(600, 0);

	sf::Texture board_image;
	sf::Sprite board_sprite;

	if (!board_image.loadFromFile("images/board.png"))
		std::cout << "[ERROR] Could not load the board image" << std::endl;

	board_sprite.scale(0.5f, 0.5f);
	board_sprite.setTexture(board_image);

    while (window.isOpen())
    {
        sf::Event event;

		if (is_selected)
		{
			shape.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
		}

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

			else if (event.type == sf::Event::Resized)
			{
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(visibleArea));
			}

			else if (event.type == sf::Event::MouseButtonPressed)
			{
				display.setString(std::to_string(is_selected));

				if (sf::Mouse::getPosition(window).x >= shape.getPosition().x - 50.0f && sf::Mouse::getPosition(window).x <= shape.getPosition().x + 50.0f &&
					sf::Mouse::getPosition(window).y >= shape.getPosition().y - 50.0f && sf::Mouse::getPosition(window).y <= shape.getPosition().y + 50.0f)
				{
					shape.setFillColor(sf::Color::Green);
					is_selected = true;
				}
			}

			else if (event.type == sf::Event::MouseButtonReleased)
			{
				is_selected = false;
				shape.setFillColor(sf::Color::Red);
			}
        }

        window.clear();

        window.draw(board_sprite);
		window.draw(shape);
		window.draw(display);

        window.display();
    }

    return 0;
}
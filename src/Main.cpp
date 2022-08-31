#include "Platform/Platform.hpp"
#include <cstdlib>
#include <ctime>

#define WIDTH 100
#define HEIGHT 100
#define EMITRATE 1

//void draw_sandbox(sf::RenderWindow*, float, float);
void particle_emitter(int, int, int);
void init_sandbox(bool);
void update_sandbox(sf::RenderWindow*, float, float);
void clear_sandbox();
void draw_cursor(sf::RenderWindow*, sf::Mouse*, int, int, int);
void draw_tool_name(sf::RenderWindow*, sf::Text*, int);

typedef struct gCell
{
	unsigned int id;
	bool moved;
	int flamability;

} gCell;

gCell grid[WIDTH][HEIGHT] = {};
int MATID = 3;
bool paused = false;

void clear_sandbox()
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			grid[y][x].id = 0;
		}
	}
}

void init_sandbox(bool moved)
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			//grid[y][x].id = id;
			grid[y][x].moved = moved;
		}
	}
}

// void draw_sandbox(sf::RenderWindow* window, float wCell, float hCell)
// {
// 	for (int y = 0; y < HEIGHT; y++)
// 	{
// 		for (int x = 0; x < WIDTH; x++)
// 		{
// 			if (grid[y][x].id == 0) // empty cell id
// 			{
// 				sf::RectangleShape rect(sf::Vector2f(wCell, hCell));
// 				rect.setPosition((x * wCell), (y * hCell));
// 				rect.setFillColor(sf::Color(150, 150, 150)); // sf::Color(150, 150, 150)
// 				window->draw(rect);
// 			}

// 			else if (grid[y][x].id == 1) // sand id
// 			{
// 				sf::RectangleShape rect(sf::Vector2f(wCell, hCell));
// 				rect.setPosition((x * wCell), (y * hCell));
// 				rect.setFillColor(sf::Color(196, 148, 14)); // 252, 186, 3 // 196, 148, 14 // 184, 139, 15
// 				window->draw(rect);
// 			}

// 			else if (grid[y][x].id == 2) // water id
// 			{
// 				sf::RectangleShape rect(sf::Vector2f(wCell, hCell));
// 				rect.setPosition((x * wCell), (y * hCell));
// 				rect.setFillColor(sf::Color(66, 135, 245)); // sf::Color(66, 135, 245)
// 				window->draw(rect);
// 			}
// 			else if (grid[y][x].id == 3) // wood id
// 			{
// 				sf::RectangleShape rect(sf::Vector2f(wCell, hCell));
// 				rect.setPosition((x * wCell), (y * hCell));
// 				rect.setFillColor(sf::Color(119, 86, 40)); // sf::Color(66, 135, 245)
// 				window->draw(rect);
// 			}
// 			else if (grid[y][x].id == 4) // smoke id
// 			{
// 				sf::RectangleShape rect(sf::Vector2f(wCell, hCell));
// 				rect.setPosition((x * wCell), (y * hCell));
// 				rect.setFillColor(sf::Color(64, 64, 64)); // sf::Color(66, 135, 245)
// 				window->draw(rect);
// 			}
// 			else if (grid[y][x].id == 5) // fire embers
// 			{
// 				sf::RectangleShape rect(sf::Vector2f(wCell, hCell));
// 				rect.setPosition((x * wCell), (y * hCell));
// 				rect.setFillColor(sf::Color(255, 98, 0)); // sf::Color(255, 98, 0)
// 				window->draw(rect);
// 			}
// 			else if (grid[y][x].id == 6) // Diamond
// 			{
// 				sf::RectangleShape rect(sf::Vector2f(wCell, hCell));
// 				rect.setPosition((x * wCell), (y * hCell));
// 				rect.setFillColor(sf::Color(161, 219, 227)); // sf::Color(255, 98, 0)
// 				window->draw(rect);
// 			}
// 		}
// 	}
// }

void particle_emitter(int x, int y, int particle)
{
	if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
	{
		grid[y][x].id = particle;
	}
}

void update_sandbox(sf::RenderWindow* window, float wCell, float hCell)
{
	for (int y = 1; y < HEIGHT - 1; y++)
	{
		for (int x = 1; x < WIDTH - 1; x++)
		{
			if (grid[y][x].id == 0) // empty cell id
			{
				sf::RectangleShape rect(sf::Vector2f(wCell, hCell));
				rect.setPosition((x * wCell), (y * hCell));
				rect.setFillColor(sf::Color(150, 150, 150)); // sf::Color(150, 150, 150)
				window->draw(rect);
			}

			else if (grid[y][x].id == 1) // sand id
			{
				sf::RectangleShape rect(sf::Vector2f(wCell, hCell));
				rect.setPosition((x * wCell), (y * hCell));
				rect.setFillColor(sf::Color(196, 148, 14)); // 252, 186, 3 // 196, 148, 14 // 184, 139, 15
				window->draw(rect);
			}

			else if (grid[y][x].id == 2) // water id
			{
				sf::RectangleShape rect(sf::Vector2f(wCell, hCell));
				rect.setPosition((x * wCell), (y * hCell));
				rect.setFillColor(sf::Color(66, 135, 245)); // sf::Color(66, 135, 245)
				window->draw(rect);
			}
			else if (grid[y][x].id == 3) // wood id
			{
				sf::RectangleShape rect(sf::Vector2f(wCell, hCell));
				rect.setPosition((x * wCell), (y * hCell));
				rect.setFillColor(sf::Color(119, 86, 40)); // sf::Color(66, 135, 245)
				window->draw(rect);
			}
			else if (grid[y][x].id == 4) // smoke id
			{
				sf::RectangleShape rect(sf::Vector2f(wCell, hCell));
				rect.setPosition((x * wCell), (y * hCell));
				rect.setFillColor(sf::Color(64, 64, 64)); // sf::Color(66, 135, 245)
				window->draw(rect);
			}
			else if (grid[y][x].id == 5) // fire embers
			{
				sf::RectangleShape rect(sf::Vector2f(wCell, hCell));
				rect.setPosition((x * wCell), (y * hCell));
				rect.setFillColor(sf::Color(255, 98, 0)); // sf::Color(255, 98, 0)
				window->draw(rect);
			}
			else if (grid[y][x].id == 6) // Diamond
			{
				sf::RectangleShape rect(sf::Vector2f(wCell, hCell));
				rect.setPosition((x * wCell), (y * hCell));
				rect.setFillColor(sf::Color(161, 219, 227)); // sf::Color(255, 98, 0)
				window->draw(rect);
			}

			if (!paused)
			{
				if (grid[y][x].id == 1 && grid[y][x].moved == false) // sand particle
				{
					if (grid[y + 1][x].id != 1 && grid[y + 1][x].id != 3 && grid[y + 1][x].id != 6) // check below
					{
						grid[y][x].id = 0;
						grid[y + 1][x].id = 1;
						grid[y + 1][x].moved = true;
						grid[y + 1][x].flamability = 105;
					}
					else if (grid[y + 1][x - 1].id != 1 && grid[y + 1][x - 1].id != 3 && grid[y + 1][x - 1].id != 6) // check below and left
					{
						grid[y][x].id = 0;
						grid[y + 1][x - 1].id = 1;
						grid[y + 1][x - 1].moved = true;
						grid[y + 1][x - 1].flamability = 105;
					}
					else if (grid[y + 1][x + 1].id != 1 && grid[y + 1][x + 1].id != 3 && grid[y + 1][x + 1].id != 6) // check below and right
					{
						grid[y][x].id = 0;
						grid[y + 1][x + 1].id = 1;
						grid[y + 1][x + 1].moved = true;
						grid[y + 1][x + 1].flamability = 105;
					}
				}

				else if (grid[y][x].id == 2 && grid[y][x].moved == false) // water particle
				{
					if (grid[y + 1][x].id == 0) // check below
					{
						grid[y][x].id = 0;
						grid[y + 1][x].id = 2;
						grid[y + 1][x].moved = true;
						grid[y + 1][x].flamability = 105;
					}
					else if (grid[y + 1][x - 1].id == 0) // check below and left
					{
						grid[y][x].id = 0;
						grid[y + 1][x - 1].id = 2;
						grid[y + 1][x - 1].moved = true;
						grid[y + 1][x - 1].flamability = 105;
					}
					else if (grid[y + 1][x + 1].id == 0) // check below and right
					{
						grid[y][x].id = 0;
						grid[y + 1][x + 1].id = 2;
						grid[y + 1][x + 1].moved = true;
						grid[y + 1][x + 1].flamability = 105;
					}
					else if (grid[y][x - 1].id == 0) // check left
					{
						grid[y][x].id = 0;
						grid[y][x - 1].id = 2;
						grid[y][x - 1].moved = true;
						grid[y][x - 1].flamability = 105;
					}
					else if (grid[y][x + 1].id == 0) // check right
					{
						grid[y][x].id = 0;
						grid[y][x + 1].id = 2;
						grid[y][x + 1].moved = true;
						grid[y][x + 1].flamability = 105;
					}
				}

				else if (grid[y][x].id == 4 && grid[y][x].moved == false) // smoke particle
				{
					if (grid[y - 1][x].id == 0) // check above
					{
						grid[y][x].id = 0;
						grid[y - 1][x].id = 4;
						grid[y - 1][x].moved = true;
						grid[y - 1][x].flamability = 105;
					}
					else if (grid[y - 1][x - 1].id == 0) // check above and left
					{
						grid[y][x].id = 0;
						grid[y - 1][x - 1].id = 4;
						grid[y - 1][x - 1].moved = true;
						grid[y - 1][x - 1].flamability = 105;
					}
					else if (grid[y - 1][x + 1].id == 0) // check above and right
					{
						grid[y][x].id = 0;
						grid[y - 1][x + 1].id = 4;
						grid[y - 1][x + 1].moved = true;
						grid[y - 1][x + 1].flamability = 105;
					}
					else if (grid[y][x - 1].id == 0) // check left
					{
						grid[y][x].id = 0;
						grid[y][x - 1].id = 4;
						grid[y][x - 1].moved = true;
						grid[y][x - 1].flamability = 105;
					}
					else if (grid[y][x + 1].id == 0) // check right
					{
						grid[y][x].id = 0;
						grid[y][x + 1].id = 4;
						grid[y][x + 1].moved = true;
						grid[y][x + 1].flamability = 105;
					}
				}

				else if (grid[y][x].id == 5 && grid[y][x].moved == false) // fire particle
				{
					int chance = 101;
					bool isDead = false;
					chance = 1 + std::rand() / ((RAND_MAX + 1u) / 100); // generate random number
					if (chance > 98)									// chance to turn into smoke
					{
						grid[y][x].id = 4;
						grid[y][x].moved = true;
						grid[y][x].flamability = 105;
					}
					else if (chance < 98 && chance > 35) // chance to die out
					{
						grid[y][x].id = 0;
						isDead = true;
					}

					if (!isDead)
					{
						if (grid[y - 1][x].id == 0) // check up
						{
							grid[y][x].id = 0;
							grid[y - 1][x].id = 5;
							grid[y - 1][x].moved = true;
							grid[y - 1][x].flamability = 105;
						}
						else
						{
							chance = 1 + std::rand() / ((RAND_MAX + 1u) / 100); // generate random number
							if (chance > grid[y - 1][x].flamability)
							{
								grid[y][x].id = 0;
								grid[y - 1][x].id = 5;
								grid[y - 1][x].moved = true;
								grid[y - 1][x].flamability = 105;
							}
						}

						if (grid[y - 1][x - 1].id == 0) // check up and left
						{
							grid[y][x].id = 0;
							grid[y - 1][x - 1].id = 5;
							grid[y - 1][x - 1].moved = true;
							grid[y - 1][x - 1].flamability = 105;
						}
						else
						{
							chance = 1 + std::rand() / ((RAND_MAX + 1u) / 100); // generate random number
							if (chance > grid[y - 1][x + 1].flamability)
							{
								grid[y - 1][x].id = 0;
								grid[y - 1][x - 1].id = 5;
								grid[y - 1][x - 1].moved = true;
								grid[y - 1][x - 1].flamability = 105;
							}
						}

						if (grid[y - 1][x + 1].id == 0) // check up and right
						{
							grid[y][x].id = 0;
							grid[y - 1][x + 1].id = 5;
							grid[y - 1][x + 1].moved = true;
							grid[y - 1][x + 1].flamability = 105;
						}
						else
						{
							chance = 1 + std::rand() / ((RAND_MAX + 1u) / 100); // generate random number
							if (chance > grid[y - 1][x + 1].flamability)
							{
								grid[y][x].id = 0;
								grid[y - 1][x + 1].id = 5;
								grid[y - 1][x + 1].moved = true;
								grid[y - 1][x + 1].flamability = 105;
							}
						}

						if (grid[y + 1][x].id != 0) // check below
						{
							chance = 1 + std::rand() / ((RAND_MAX + 1u) / 100); // generate random number
							if (chance > grid[y + 1][x].flamability)
							{
								grid[y][x].id = 0;
								grid[y + 1][x].id = 5;
								grid[y + 1][x].moved = true;
								grid[y + 1][x].flamability = 105;
							}
						}
					}
				}
			}
		}
	}
}

void draw_cursor(sf::RenderWindow* window, sf::Mouse* mouse, int radius, int wCell, int hCell)
{
	int xgCell = mouse->getPosition(*window).x / wCell;
	int ygCell = mouse->getPosition(*window).y / hCell;

	sf::RectangleShape rect(sf::Vector2f((radius * 2) * 8, (radius * 2) * 8));
	rect.setPosition((xgCell * wCell) - (wCell * radius), (ygCell * hCell) - (hCell * radius));
	rect.setOutlineColor(sf::Color::Black);
	rect.setOutlineThickness(-1);
	rect.setFillColor(sf::Color::Transparent);
	window->draw(rect);
}

void draw_tool_name(sf::RenderWindow* window, sf::Text* text, int MATID)
{
	sf::Font font;
	font.loadFromFile("src/arial.ttf");

	switch (MATID)
	{
		case 1:
			text->setFont(font);
			text->setString("SAND");
			text->setCharacterSize(30);
			text->setPosition(0, 0);
			window->draw(*text);
			break;

		case 2:
			text->setFont(font);
			text->setString("WATER");
			text->setCharacterSize(30);
			text->setPosition(0, 0);
			window->draw(*text);
			break;

		case 3:
			text->setFont(font);
			text->setString("WOOD");
			text->setCharacterSize(30);
			text->setPosition(0, 0);
			window->draw(*text);
			break;

		case 4:
			text->setFont(font);
			text->setString("SMOKE");
			text->setCharacterSize(30);
			text->setPosition(0, 0);
			window->draw(*text);
			break;

		case 5:
			text->setFont(font);
			text->setString("FIRE");
			text->setCharacterSize(30);
			text->setPosition(0, 0);
			window->draw(*text);
			break;

		case 6:
			text->setFont(font);
			text->setString("DIAMOND");
			text->setCharacterSize(30);
			text->setPosition(0, 0);
			window->draw(*text);
			break;

		default:
			break;
	}
}

int main()
{
	util::Platform platform;

	sf::RenderWindow window;
	// in Windows at least, this must be called before creating the window
	float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
	// Use the screenScalingFactor
	window.create(sf::VideoMode(800.0f * screenScalingFactor, 800.0f * screenScalingFactor), "Particle Simulation");
	//platform.setIcon(window.getSystemHandle());

	// initialise all elements of grid to a 1

	float wCell = window.getSize().x / WIDTH;
	float hCell = window.getSize().y / HEIGHT;

	//int EmitIndex = 0;
	int radius = 1;
	std::srand(std::time(nullptr)); // use current time as seed for random generator

	sf::Event event;
	sf::Mouse mouse;
	sf::Text text;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseWheelMoved)
			{
				if (event.mouseWheel.delta > 0)
				{
					radius += 1;
				}
				else
				{
					radius -= (radius > 0) ? 1 : 0;
				}
			}

			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
					case sf::Keyboard::Num1:
						MATID = 1; // sand
						break;

					case sf::Keyboard::Num2:
						MATID = 2; // water
						break;

					case sf::Keyboard::Num3:
						MATID = 3; // wood
						break;

					case sf::Keyboard::Num4:
						MATID = 4; // smoke
						break;

					case sf::Keyboard::Num5:
						MATID = 5; // smoke
						break;

					case sf::Keyboard::Num6:
						MATID = 6; // diamond
						break;

					case sf::Keyboard::Space:
						paused = (!paused) ? true : false;
						break;

					case sf::Keyboard::C:
						clear_sandbox();
						break;

					default:
						break;
				}
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			int chance = 0;
			// draw at mouse position
			int xgCell = sf::Mouse::getPosition(window).x / wCell;
			int ygCell = sf::Mouse::getPosition(window).y / hCell;

			if (radius == 0)
			{
				if (xgCell - radius >= 0 && xgCell + radius <= WIDTH && ygCell - radius >= 0 && ygCell + radius <= HEIGHT)
				{
					grid[ygCell][xgCell].id = MATID;
				}
			}

			if (xgCell - radius >= 0 && xgCell + radius <= WIDTH && ygCell - radius >= 0 && ygCell + radius <= HEIGHT)
			{
				for (int y = ygCell - radius; y < ygCell + radius; y++)
				{
					for (int x = xgCell - radius; x < xgCell + radius; x++)
					{
						if (grid[y][x].id == 0 && MATID != 3 && MATID != 6) // is Empty
						{
							chance = 1 + std::rand() / ((RAND_MAX + 1u) / 100); // generate random number
							if (chance > 70)
							{
								grid[y][x].id = MATID;
							}
						}
						else if (grid[y][x].id == 0 && MATID == 3)
						{
							grid[y][x].id = MATID;
							grid[y][x].flamability = 0;
						}
						else if (grid[y][x].id == 0 && MATID == 6)
						{
							grid[y][x].id = MATID;
							grid[y][x].flamability = 105;
						}
					}
				}
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			// draw empty cell at mouse position
			int xgCell = sf::Mouse::getPosition(window).x / wCell;
			int ygCell = sf::Mouse::getPosition(window).y / hCell;

			if (radius == 0)
			{
				if (xgCell - radius >= 0 && xgCell + radius <= WIDTH && ygCell - radius >= 0 && ygCell + radius <= HEIGHT)
				{
					grid[ygCell][xgCell].id = 0;
				}
			}

			if (xgCell - radius >= 0 && xgCell + radius <= WIDTH && ygCell - radius >= 0 && ygCell + radius <= HEIGHT)
			{
				for (int y = ygCell - radius; y < ygCell + radius; y++)
				{
					for (int x = xgCell - radius; x < xgCell + radius; x++)
					{
						grid[y][x].id = 0;
					}
				}
			}
		}

		init_sandbox(false);

		window.clear(/*sf::Color(150, 150, 150)*/);
		// if (EmitIndex % EMITRATE == 0)
		// {
		// 	particle_emitter(15, 15, 2);
		// 	particle_emitter(75, 15, 1);
		// }
		//particle_emitter(75, 10, 1);
		//draw_sandbox(&window, wCell, hCell);
		update_sandbox(&window, wCell, hCell);
		draw_cursor(&window, &mouse, radius, wCell, hCell);
		draw_tool_name(&window, &text, MATID);
		window.display();
		//EmitIndex++;
	}

	return 0;
}

#include "Menu.h"
using namespace std;
Menu::Menu(float Width,float height)
{
	if (!font.loadFromFile("arial.ttf"));
	{ }
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::Blue);
	mainMenu[0].setString("Play");
	mainMenu[0].setPosition(Vector2f(Width / 2 - 60, height / (nitems + 1) * 1));

	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(Color::White);
	mainMenu[1].setString("Options");
	mainMenu[1].setPosition(Vector2f(Width / 2 - 80, height / (nitems + 1) * 2));

	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(Color::White);
	mainMenu[2].setString("Story");
	mainMenu[2].setPosition(Vector2f(Width / 2 - 65, height / (nitems + 1) * 3));

	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(Color::White);
	mainMenu[3].setString("Exit");
	mainMenu[3].setPosition(Vector2f(Width / 2 - 60, height / (nitems + 1) * 4));


	mainMenuSelected = 0;
}

Menu::~Menu()
{}
void Menu::draw(RenderWindow& window)
{
	for (int i = 0; i < nitems; i++)
	{
		window.draw(mainMenu[i]);
	}
}
void Menu::movedown()
{
	if (mainMenuSelected + 1 <= nitems)
	{
		mainMenu[mainMenuSelected].setFillColor(Color::White);
		mainMenuSelected++;
		if (mainMenuSelected == 4)
		{
			mainMenuSelected = 0;
		}
		mainMenu[mainMenuSelected].setFillColor(Color::Blue);
	}
}
void Menu::moveup()
{
	if (mainMenuSelected - 1 > -1)
	{
		mainMenu[mainMenuSelected].setFillColor(Color::White);
		mainMenuSelected--;
		if (mainMenuSelected == -1)
		{
			mainMenuSelected = 1;
		}
		mainMenu[mainMenuSelected].setFillColor(Color::Blue);
	}
}
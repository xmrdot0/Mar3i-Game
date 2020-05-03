#include <SFML/Graphics.hpp>
#pragma once
#define nitems 4
using namespace sf;
class Menu
{
public:
	Menu(float wight, float height);
	void draw(RenderWindow &window);
	void moveup();
	void movedown();
	~Menu();
	int mainmenupressed()
	{
		return mainMenuSelected;
	}
private:
	int mainMenuSelected;
	Font font;
	Text mainMenu[nitems];
};


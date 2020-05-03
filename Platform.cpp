#include "Platform.h"
#include <SFML/Graphics.hpp>
using namespace sf;

Platform::Platform(Texture* texture, Vector2f size, Vector2f position)
{
    body.setSize(size);
    body.setOrigin(195, -90);
    body.setTexture(texture);
    body.setPosition(position);
}
Platform::~Platform()
{

}
void Platform::Draw(RenderWindow& window)
{
    window.draw(body);
}
#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h"
using namespace sf;
class Platform
{
public:
    Platform(Texture* texture, Vector2f size, Vector2f position);
    ~Platform();
    void Move(Vector2f move) { body.move(move); }
    void SetPosition(Vector2f pos) { body.setPosition(pos); }
    void Draw(RenderWindow& window);
    Collider GetCollider() { return Collider(body); }
    Vector2f GetPosition() { return body.getPosition(); }
private:
    RectangleShape body;
};

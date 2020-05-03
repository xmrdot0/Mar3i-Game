#pragma once
#include <Sfml\Graphics.hpp>
#include "Animation.h"
#include "Collider.h"
using namespace sf;
class Player
{
public:
    Player(Texture* texture, Vector2u imageCount, float switchTime, float speed, float jumpHeight);
    ~Player();
    void Update(float deltaTime);
    void Draw(RenderWindow& window);
    void onCollision(Vector2f direction);
    void SetPosition(Vector2f pos) { body.setPosition(pos); }
    Vector2f GetPosition() { return body.getPosition(); }
    Collider GetCollider() { return Collider(body); }
    bool canJ() { return canJump; }
private:
    RectangleShape body;
    Animation animation;
    unsigned int row;
    float speed;
    bool faceRight;
    Vector2f velocity;
    bool canJump;
    float jumpHeight;
    Vector2f pos;
};
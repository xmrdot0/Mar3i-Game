#include "Player.h"
#include <SFML/Audio.hpp>
#include "Animation.h"

#include <iostream>

using namespace sf;

Player::Player(Texture* texture, Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
    animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    this->jumpHeight = jumpHeight;
    row = 0;
    faceRight = true;

    body.setSize(Vector2f(50.0f, 60.0f));
    body.setOrigin(200, -90);
    body.setTexture(texture);
}

Player::~Player()
{

}

void Player::Update(float deltaTime)
{

    velocity.x = 0;
    bool canRun = true;
    bool lvl1 = true;
    if (body.getPosition().x >= 5326.35)
    {
        lvl1 = false;
    }
    if (body.getPosition().x >= 5500)
    {
        lvl1 = true;
    }
    if (lvl1)
    {
        if (body.getPosition().x >= 3193.123 && body.getPosition().x <= 3600.4 && Keyboard::isKeyPressed(Keyboard::D) && body.getPosition().y > -10.0)
        {
            velocity.x -= (speed - 20);
            canRun = false;
        }

        if (body.getPosition().x >= 3193.123 && body.getPosition().x <= 3600.4 && Keyboard::isKeyPressed(Keyboard::A) && body.getPosition().y > -10.0)
        {
            velocity.x += (speed - 20);
            canRun = false;
        }
        if (Keyboard::isKeyPressed(Keyboard::LShift) && Keyboard::isKeyPressed(Keyboard::D) && body.getPosition().x >= 3193.123 && body.getPosition().x <= 3600.4)
        {
            canRun = false;
        }
        if (Keyboard::isKeyPressed(Keyboard::LShift) && Keyboard::isKeyPressed(Keyboard::A) && body.getPosition().x >= 3193.123 && body.getPosition().x <= 3600.4)
        {
            canRun = false;
        }
        if (Keyboard::isKeyPressed(Keyboard::A )&& body.getPosition().x >= 20) {
            velocity.x -= speed;
        }
        if (Keyboard::isKeyPressed(Keyboard::D)) {
            velocity.x += speed;
        }
        if (Keyboard::isKeyPressed(Keyboard::Space) && canJump) {

            canJump = false;
            if (body.getPosition().x >= 3193.123 && body.getPosition().x <= 3600.4)
            {
                velocity.y = -sqrtf(2.0f * 390.0f * jumpHeight);
            }
            else
            {
                velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
                //gravity equation
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::LShift) && Keyboard::isKeyPressed(Keyboard::D) && canRun)
        {
            velocity.x = velocity.x + speed - 100;
        }
        if (Keyboard::isKeyPressed(Keyboard::LShift) && Keyboard::isKeyPressed(Keyboard::A) && canRun && body.getPosition().x>=20)
        {
            velocity.x = velocity.x - speed + 100;
        }
    }

    velocity.y += 981.0f * deltaTime;

    if (velocity.x == 0.0f) {
        row = 1;
    }

    else
    {
        row = 0;

        if (velocity.x > 0) {
            faceRight = true;
        }
        else {
            faceRight = false;
        }
    }


    animation.Update(row, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);
    body.move(velocity * deltaTime);
}

void Player::Draw(RenderWindow& window)
{
    window.draw(body);
}
void Player::onCollision(Vector2f direction)
{
    if (direction.x < 0.0f)
    {
        velocity.x = 0.0f;
    }
    else if (direction.x > 0.0f)
    {
        velocity.x = 0.0f;
    }
    if (direction.y < 0.0f)
    {
        velocity.y = 0.0f;
        canJump = true;
        //Collision on the bottom
    }
    if (direction.y > 0.0f)
    {
        velocity.y = 0.0f;
    }
}
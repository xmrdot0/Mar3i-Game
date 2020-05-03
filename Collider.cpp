#include <SFML/Graphics.hpp>
#include "Collider.h"
using namespace sf;
using namespace std;


Collider::Collider(RectangleShape& body) :
    body(body)
{

}

Collider::~Collider()
{

}


bool Collider::CheckCollision(Collider other, Vector2f& direction, float push)
{
    Vector2f otherPosition = other.GetPosition();
    Vector2f otherHalfSize = other.GetHalfSize();
    Vector2f thisPosition = GetPosition();
    Vector2f thisHalfSize = GetHalfSize();

    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;

    float interSectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x)+17;
    float interSectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

    if (interSectX < 0.0f && interSectY < 0.0f)
    {
        push = min(max(push, 0.0f), 1.0f);

        if (interSectX > interSectY)
        {
            if (deltaX > 0.0f)
            {
                Move(interSectX * (1.0f - push), 0.0f);
                other.Move(-interSectX * push, 0.0f);

                direction.x = 1.0f;
                direction.y = 0.0f;
            }
            else {
                Move(-interSectX * (1.0f - push), 0.0f);
                other.Move(interSectX * push, 0.0f);
                direction.x = -1.0f;
                direction.y = 0.0f;
            }
        }
        else
        {
            if (deltaY > 0.0f)
            {
                Move(0.0f, interSectY * (1.0f - push));
                other.Move(0.0f, -interSectY * push);
                direction.x = 0.0f;
                direction.y = 1.0f;
            }
            else {
                Move(0.0f, -interSectY * (1.0f - push));
                other.Move(0.0f, interSectY * push);
                direction.x = 0.0f;
                direction.y = -1.0f;
            }
        }

        return true;
    }

    return false;
}
#include "cocos2d.h"
#include "Vector.h"
#include <stack>
using namespace cocos2d;
class GameObject : public Sprite
{
    public:
        void onCollision(GameObject*);
        GameObject();
        static GameObject* create();
        bool fixed;
        void update();
        PhysicsVector pos;
        PhysicsVector velocity;
        int mass;
        std::stack<PhysicsVector> forces;
        void addForce(PhysicsVector force, GameObject* from);
};

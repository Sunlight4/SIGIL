//
//  Wall.hpp
//  SIGIL
//
//  Created by Ethan Saff on 11/19/15.
//
//

#ifndef Wall_hpp
#define Wall_hpp

#include <stdio.h>
#include "Object.h"
#endif /* Wall_hpp */


class Wall: public GameObject {
    double bouncy;
    void onCollision(GameObject*);
    public:
        Wall();
        static Wall* create();
        virtual PhysicsVector getNormal(int angle);
};
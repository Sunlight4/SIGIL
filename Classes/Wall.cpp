//
//  Wall.cpp
//  SIGIL
//
//  Created by Ethan Saff on 11/19/15.
//
//

#include "Wall.hpp"
#include <cmath>
void Wall::onCollision(GameObject* other) {
    double angle = acos(PhysicsVector::cosAngle(PhysicsVector(other->getPosition())-pos, PhysicsVector(0,1)));
    PhysicsVector normal = getNormal (angle);
    double cosine = PhysicsVector::cosAngle(other->velocity, normal);
    other->addForce(cosine*bouncy*other->velocity.magnitude(), this);
}
PhysicsVector Wall::getNormal(int angle) {
    return PhysicsVector(0, 1);
}

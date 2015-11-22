//
//  Object.cpp
//  SIGIL
//
//  Created by Ethan Saff on 11/19/15.
//
//
#include "cocos2d.h"
#include "Object.h"
using namespace cocos2d;
void GameObject::update() {
    pos.x=getPosition().x;
    pos.y=getPosition().y;
    PhysicsVector sumforces=PhysicsVector(0,0);
    while (forces.size()>0) {
        PhysicsVector force=forces.top();
        sumforces+=force;
        forces.pop();
    };
    if (fixed) {
        return;
    }
    velocity+=sumforces/(float) mass;
    pos+=velocity;
    setPosition(pos.x, pos.y);
}

void GameObject::addForce(PhysicsVector force, GameObject* from) {
    forces.push(force);
    from->forces.push(-force);
    
}
void GameObject::onCollision(GameObject* other) {
    return;
}
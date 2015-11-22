#include <cmath>
class PhysicsVector{
     public:
        int x, y;
        PhysicsVector operator+(PhysicsVector other) {
            return PhysicsVector(x+other.x, y+other.y);
        }
        PhysicsVector & operator+=(const PhysicsVector &other) {
            x+=other.x;
            y+=other.y;
            return *this;
        };
        PhysicsVector operator-(PhysicsVector other) {
            return PhysicsVector(x-other.x, y-other.y);
        }
        PhysicsVector & operator-=(const PhysicsVector &other) {
            x-=other.x;
            y-=other.y;
            return *this;
        };
        PhysicsVector operator/(float other) {
            return PhysicsVector(x/other, y/other);
        }
        PhysicsVector (int xx =0, int yy =0) {
            x=xx;
            y=yy;
        }
        PhysicsVector (cocos2d::Vec2 vv) {
            x=vv.x;
            y=vv.y;
        }
        PhysicsVector normalize() {
            return PhysicsVector(x/magnitude(), y/magnitude());
        }
        double magnitude() {
            return sqrt(x*x+y*y);
        }
        double operator*(PhysicsVector other) {
            return x*other.x+y*other.y;
        }
        static double cosAngle (PhysicsVector a, PhysicsVector b) {
            double result;
            result=(a*b)/(a.normalize()*b.normalize());
            return result;
        }
        PhysicsVector operator-()  {
            return PhysicsVector(-x, -y);
        }
    void release();
 };

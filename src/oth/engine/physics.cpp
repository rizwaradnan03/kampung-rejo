#include <oth/logic/physics.hpp>

bool Physics::isCollide(float xm, float ym, float wm, float hm, float xe, float ye, float we, float he){
    if(xm + wm <= xe || xe + we <= xm || ym + hm <= ye || ye + he <= ym){
        return false;
    }

    return false;
}
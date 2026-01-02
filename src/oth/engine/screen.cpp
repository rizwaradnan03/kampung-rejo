#include <oth/node/screen.hpp>
#include <oth/engine/render.hpp>
#include <vector>

std::vector<Render*> Screen::getAllObject(){
    return this->obj;
}

void Screen::setObject(Render* object){
    this->obj.push_back(object);
}
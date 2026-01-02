#include <oth/class/screen.hpp>
#include <oth/render.hpp>
#include <vector>

std::vector<Render*> Screen::getAllObject(){
    return this->obj;
}
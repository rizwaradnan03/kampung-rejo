#include <oth/engine/config.hpp>

float Config::getTime(){
    return time;
}

void Config::setTime(float value){
    time += value;
}
#include <oth/engine/sound.hpp>
#include <iostream>
#include <string>

Sound::Sound(const std::string& path, std::string name): buffer(), sound(buffer){
    if(!buffer.loadFromFile(path)){
        std::cerr << "Failed load sound: " << path << std::endl;
    }

    sound.setBuffer(buffer);
    this->name = name;
}

void Sound::Play(){
    sound.play();
}

std::string Sound::get_name(){
    return this->name;
}
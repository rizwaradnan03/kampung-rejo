#include <oth/engine/sound.hpp>
#include <iostream>
#include <string>

Sound::Sound(const std::string& path): buffer(), sound(buffer){
    if(!buffer.loadFromFile(path)){
        std::cerr << "Failed load sound: " << path << std::endl;
    }

    sound.setBuffer(buffer);
}

void Sound::Play(){
    sound.play();
}
#include <oth/sound.hpp>

Sound::Sound(sf::SoundBuffer buffer){
    this->buffer = buffer;
}

void Sound::Play(){
    sf::Sound sound(this->buffer);
    sound.play();
}
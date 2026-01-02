#ifndef SOUND_HPP
#define SOUND_HPP

#include <SFML/Audio.hpp>

class Sound {
    public:
        Sound(sf::SoundBuffer buffer);
        void Play();
        
    private:
        sf::SoundBuffer buffer;
};

#endif
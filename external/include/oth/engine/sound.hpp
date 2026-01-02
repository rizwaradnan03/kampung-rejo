#ifndef SOUND_HPP
#define SOUND_HPP

#include <SFML/Audio.hpp>
#include <string>

class Sound {
    public:
        Sound(const std::string& path);
        void Play();
        
    private:
        sf::SoundBuffer buffer;
        sf::Sound sound;
};

#endif
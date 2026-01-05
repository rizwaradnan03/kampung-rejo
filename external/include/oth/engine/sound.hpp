#ifndef SOUND_HPP
#define SOUND_HPP

#include <SFML/Audio.hpp>
#include <string>

class Sound {
    public:
        Sound(const std::string& path, std::string name);
        void Play();
        std::string get_name();
        
    private:
        std::string name;
        sf::SoundBuffer buffer;
        sf::Sound sound;
};

#endif
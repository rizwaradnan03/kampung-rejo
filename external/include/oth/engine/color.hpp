#ifndef COLOR_HPP
#define COLOR_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include <sstream>

class Color {
    public:
        std::string colorToHex(const sf::Color &c);
        sf::Color hexToColor(const std::string &hex);
};

#endif

#include <oth/engine/color.hpp>

std::string Color::colorToHex(const sf::Color &c){
    std::stringstream ss;
    ss << "#" 
       << std::hex << std::setw(2) << std::setfill('0') << (int)c.r
       << std::hex << std::setw(2) << std::setfill('0') << (int)c.g
       << std::hex << std::setw(2) << std::setfill('0') << (int)c.b;
    return ss.str();
}

sf::Color Color::hexToColor(const std::string &hex){
    unsigned int r, g, b;
    if(hex.size() == 7 && hex[0] == '#'){
        sscanf(hex.c_str(), "#%02x%02x%02x", &r, &g, &b);
        return sf::Color(r, g, b);
    }
    return sf::Color::White;
}
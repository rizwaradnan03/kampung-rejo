#include <SFML/Graphics.hpp>
#include <oth/engine/game.hpp>
#include <oth/engine/config.hpp>
#include <oth/engine/display.hpp>

int main(){    
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode({1920, 1080}), "Kampung Rejo");
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();

    Game g;
    g.Run(window);

    return 0;
}
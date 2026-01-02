#include <SFML/Graphics.hpp>
#include <oth/window/display.hpp>
#include <oth/input.hpp>
#include <oth/config.hpp>
#include <oth/player.hpp>

int main(){
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({Display::width, Display::height}), "Kampung Rejo");
    Config cf;
    Player py(sf::Color::Green, 150, 100);
    
    while(window->isOpen()){
        window->clear(sf::Color::Blue);
        cf.setTime(0.1);

        while(const std::optional event = window->pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window->close();
            }else{
                py.Handle(*event);
            }
        }

        py.shapeRender(window);
        window->display();
    }

    return 0;
}
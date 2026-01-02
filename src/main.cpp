#include <SFML/Graphics.hpp>
#include <oth/window/display.hpp>
#include <oth/input.hpp>

int main(){
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({Display::width, Display::height}), "Kampung Rejo");
    
    while(window->isOpen()){
        while(const std::optional event = window->pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window->close();
            }else{
                InputHandling::Run(*event);
            }
        }

        window->clear(sf::Color::Blue);
        window->display();
    }

    return 0;
}
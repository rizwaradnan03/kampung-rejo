#include <SFML/Graphics.hpp>
#include <oth/window/display.hpp>
#include <oth/input.hpp>
#include <oth/config.hpp>
#include <oth/player.hpp>
#include <oth/class/screen.hpp>
#include <oth/class/block/rectangle_block.hpp>

int main(){
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({Display::width, Display::height}), "Kampung Rejo");
    Player py(sf::Color::Green, 150, 100);
    Screen scr;
    Config cf;
    RectangleBlock bl(sf::Color::Red, 50, 50);

    scr.setObject(&bl);
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

        std::vector<Render*> obj = scr.getAllObject();
        for(int i = 0;i < scr.getAllObject().size();i++){
            obj[i]->shapeRender(window);
        }

        py.shapeRender(window);
        window->display();
    }

    return 0;
}
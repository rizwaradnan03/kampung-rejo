#include <SFML/Graphics.hpp>
#include <oth/engine/display.hpp>
#include <oth/engine/input.hpp>
#include <oth/engine/config.hpp>
#include <oth/engine/player.hpp>
#include <oth/node/screen.hpp>
#include <oth/node/block/rectangle_block.hpp>
#include <iostream>

int main(){
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({Display::width, Display::height}), "Kampung Rejo");
    Player py(sf::Color::Green, 150, 100);
    Screen scr;
    Config cf;
    RectangleBlock bl(sf::Color::Red, 50, 50);

    scr.setObject(&bl);
    while(window->isOpen()){
        window->clear(sf::Color::Blue);
        cf.setTime(0.02);

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

        // std::cout << "Timo : " << cf.getTime() << std::endl;

        py.shapeRender(window);
        window->display();
    }

    return 0;
}
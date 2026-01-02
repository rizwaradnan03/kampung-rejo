#include <oth/engine/game.hpp>
#include <SFML/Graphics.hpp>
#include <oth/engine/display.hpp>
#include <oth/engine/input.hpp>
#include <oth/engine/config.hpp>
#include <oth/engine/player.hpp>
#include <oth/node/screen.hpp>
#include <oth/node/block/rectangle_block.hpp>
#include <oth/node/tilemap.hpp>
#include <iostream>
#include <vector>
#include <thread>
#include <oth/engine/sound.hpp>

void Game::Run(sf::RenderWindow *window){
    std::vector<Tilemap*> tilemaps;
    Player py(sf::Color::Green, 50, 50);
    Screen scr;
    Config cf;

    Tilemap tm(1);

    // Sound vineBoom("assets/sound/vine-boom.mp3");
    // vineBoom.Play();

    int yVal = 0, xVal = 0;
    while (yVal < 21){
        while (xVal < 28){
            RectangleBlock *bl = new RectangleBlock(
                sf::Color::Blue,
                40,
                40,
                xVal * 40,
                yVal * 40);

            tm.setTile(yVal, xVal, bl);
            xVal++;
        }

        xVal = 0;
        yVal++;
    }

    tilemaps.push_back(&tm);

    auto lastFrameTime = std::chrono::steady_clock::now();
    while (window->isOpen()){
        auto currentFrameTime = std::chrono::steady_clock::now();
        std::chrono::duration<float> deltaTime = currentFrameTime - lastFrameTime;
        lastFrameTime = currentFrameTime;
        float dt = deltaTime.count();

        window->clear();
        
        for(int i = 0;i < tilemaps.size();i++){
            tilemaps[i]->renderTiles(window);
        }

        while (const std::optional event = window->pollEvent()){
            if (event->is<sf::Event::Closed>()){
                window->close();
            }
            else{
                py.Process(dt, *event);
            }
        }

        py.shapeRender(window);
        window->display();
    }
}
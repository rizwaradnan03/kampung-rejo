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
#include <oth/engine/initialization.hpp>

// Sound vineBoom("assets/sound/vine-boom.mp3");
// vineBoom.Play();

void Game::setTileMap(Tilemap *tm){
    this->tilemaps.push_back(tm);
}

void Game::Run(sf::RenderWindow *window){
    Initialization init;
    this->database = init.InitDatabase();
    this->setTileMap(init.InitTileMaps(this->database));

    Player py(sf::Color::Green, 50, 50, this->database);
    Screen scr;
    Config cf;
    
    auto lastFrameTime = std::chrono::steady_clock::now();
    while (window->isOpen()){
        auto currentFrameTime = std::chrono::steady_clock::now();
        std::chrono::duration<float> deltaTime = currentFrameTime - lastFrameTime;
        lastFrameTime = currentFrameTime;
        float dt = deltaTime.count();

        window->clear();
        
        for(int i = 0;i < this->tilemaps.size();i++){
            this->tilemaps[i]->renderTiles(window);
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
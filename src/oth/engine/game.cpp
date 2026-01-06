#include <oth/engine/game.hpp>
#include <SFML/Graphics.hpp>
#include <oth/engine/display.hpp>
#include <oth/engine/input.hpp>
#include <oth/engine/config.hpp>
#include <oth/node/body/player.hpp>
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
    this->tilemaps = init.InitTileMaps(this->database);

    Player py(sf::Color::Green, 32, 32, this->database);
    Screen scr;
    Config cf;

    this->camera.setSize(sf::Vector2f(1280.f, 720.f));
    this->camera.zoom(0.4f);

    sf::Clock clock;

    int frameCount = 0;
    float fps = 0.f;

    auto lastFrameTime = std::chrono::steady_clock::now();
    while (window->isOpen()){
        auto currentFrameTime = std::chrono::steady_clock::now();
        std::chrono::duration<float> deltaTime = currentFrameTime - lastFrameTime;
        lastFrameTime = currentFrameTime;
        float dt = deltaTime.count();

        this->camera.setCenter(py.get_position());
        
        window->setView(this->camera);

        window->clear();
        
        for(int i = 0;i < this->tilemaps.size();i++){
            this->tilemaps[i]->renderTiles(window);
        }
        
        while (const std::optional event = window->pollEvent()){
            if (event->is<sf::Event::Closed>()){
                window->close();
            }else{
                py._input_handle(dt, *event);
            }
        }

        frameCount++;
        sf::Time elapsed = clock.getElapsedTime();
        if(elapsed.asSeconds() >= 1.0f){
            fps = frameCount / elapsed.asSeconds();
            frameCount = 0;
            clock.restart();

            fps = 0;
        }

        py.Process(dt);
        py._shape_render(window);
        window->display();
    }
}
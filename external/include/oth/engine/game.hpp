#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <oth/engine/database.hpp>
#include <vector>
#include <oth/node/tilemap.hpp>
#include "sound.hpp"

class Game {
    public:
        void Run(sf::RenderWindow *window);
        void setTileMap(Tilemap *tm);

    private:
        Database *database;
        std::vector<Tilemap*> tilemaps;
        std::vector<Sound*> sounds;
};

#endif
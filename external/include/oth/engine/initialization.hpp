#ifndef INITIALIZATION_HPP
#define INITIALIZATION_HPP

#include <SFML/Graphics.hpp>
#include <oth/engine/database.hpp>
#include <oth/node/tilemap.hpp>

class Initialization {
    public: 
        Database* InitDatabase();
        Tilemap* InitTileMaps();
};

#endif
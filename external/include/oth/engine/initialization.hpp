#ifndef INITIALIZATION_HPP
#define INITIALIZATION_HPP

#include <SFML/Graphics.hpp>
#include <oth/engine/database.hpp>
#include <oth/node/tilemap.hpp>
#include "sound.hpp"

class Initialization {
    public: 
        Database* InitDatabase();
        Tilemap* InitTileMaps(Database *database);
        std::vector<Sound*> InitSounds();
};

#endif
#ifndef INITIALIZATION_HPP
#define INITIALIZATION_HPP

#include <SFML/Graphics.hpp>
#include <oth/engine/database.hpp>
#include <oth/node/tilemap.hpp>
#include "sound.hpp"
#include <vector>

class Initialization {
    public: 
        Database* InitDatabase();
        std::vector<Tilemap*> InitTileMaps(Database *database);
        std::vector<Sound*> InitSounds();
        
        void InitMovementList();
        void InitMovementRule();
        std::vector<sf::Texture> get_movement_list_by_action(std::string action);

    private:
        std::vector<std::pair<std::string, int>> movement_rules;
        sf::Texture movement_lists[2][6];
};

#endif
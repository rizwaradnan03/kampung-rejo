#include <oth/engine/initialization.hpp>
#include <oth/engine/database.hpp>
#include <oth/node/tilemap.hpp>
#include <string>
#include <vector>
#include <oth/engine/color.hpp>
#include <iostream>

Database *Initialization::InitDatabase()
{
    Database *db = new Database("game.db");
    Color* c;
    int cl = 3;

    std::string ic[cl] = {
        R"(
        CREATE TABLE IF NOT EXISTS player (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            color TEXT NOT NULL,
            width FLOAT NOT NULL,
            height FLOAT NOT NULL
        );
    )",
        R"(
        CREATE TABLE IF NOT EXISTS tilemaps (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            priority INTEGER NOT NULL
        )
    )",
        R"(
        CREATE TABLE IF NOT EXISTS tiles (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            tilemap_id INTEGER,
            color TEXT NOT NULL,
            width FLOAT NOT NULL,
            height FLOAT NOT NULL,
            x_position INTEGER NOT NULL,
            y_position INTEGER NOT NULL,
            FOREIGN KEY(tilemap_id) REFERENCES tilemaps(id)
        )
    )"};

    for (int i = 0; i < cl; i++)
    {
        db->executeQuery(ic[i].c_str());
    }

    std::string ic2[1] = {
        R"(
        INSERT INTO tilemaps(priority) VALUES(1);
    )"};

    for(int i = 0;i < 1;i++){
        db->executeQuery(ic2[i].c_str());
    }

    return db;
}

std::vector<Tilemap*> Initialization::InitTileMaps(Database *database){
    std::vector<Tilemap*> tilemaps;

    for(int i = 0;i < 2;i++){
        Tilemap *tm = new Tilemap(i + 1);

        int xp = 0, yp = 0;
        while(yp < (640 / 32)){
            while(xp < (864 / 32)){
                int whxy = 32;
                sf::Color col = sf::Color::Blue;

                RectangleBlock *rb = new RectangleBlock(col, whxy, whxy, xp * whxy, yp * whxy);
                tm->setTile(yp, xp, rb);

                xp++;
            }
            xp = 0;
            yp++;
        }

        tilemaps.push_back(tm);
    }

    return tilemaps;
}

std::vector<Sound*> Initialization::InitSounds(){
    std::vector<Sound*> sounds;

    Sound *vine_boom = new Sound("assets/sound/vine-boom.mp3", "vine-boom");
    sounds.push_back(vine_boom);

    return sounds;
}

void Initialization::InitMovementList(){
    std::string txts[2][2] = {
        {
            "idle_bottom",
            "idle_bottom"
        },
        {
            "idle_right",
            "idle_right"
        },
    };

    // initialize the texture
    for(int i = 0;i < 2;i++){
        std::vector<sf::Texture> mvs;

        for(int j = 0;j < 6;j++){
            std::string stringified = "assets/player/";
            if(i == 0){
                stringified += "idle_bottom/";
            }else if(i == 1){
                stringified += "idle_right/";
            }

            std::string strf = std::to_string(j+1);
            stringified += txts[i][0] + "_" + strf + ".png";
            
            if(!this->movement_lists[i][j].loadFromFile(stringified)){
                std::cout << "Failed To Load Texture!!" << std::endl;
            }
        }
    }
}

void Initialization::InitMovementRule(){
    std::string movements[4] = {"idle_bottom", "idle_right", "idle_left", "idle_top"};

    for(int i = 0;i < 4;i++){
        this->movement_rules.push_back(std::make_pair(movements[i], i));
    }
}

std::vector<sf::Texture> Initialization::get_movement_list_by_action(std::string action){
    std::vector<sf::Texture> lists;

    for(int i = 0;i < this->movement_rules.size();i++){
        std::pair<std::string, int> mr = this->movement_rules[i];

        if(mr.first == action){
            for(int j = 0;j < 6;j++){
                lists.push_back(this->movement_lists[mr.second][j]);
            }
        }
    }

    return lists;
}
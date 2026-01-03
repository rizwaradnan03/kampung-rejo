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

    int yVal = 0, xVal = 0;
    while (yVal < 21)
    {
        while (xVal < 28)
        {

            std::string colorHex = c->colorToHex(sf::Color::Blue);

            std::stringstream sql;
            sql << "INSERT INTO tiles (color, width, height, x_position, y_position) VALUES ('"
            << colorHex << "', "
            << 40 << ", "
            << 40 << ", "
            << 40 * xVal << ", "
            << 40 * yVal << ");";

            std::string query = sql.str();
            std::cout << "Query Se : " << query << std::endl;
            db->executeQuery(query.c_str());

            xVal++;
        }

        xVal = 0;
        yVal++;
    }

    // std::cout << "Berandalan" << std::endl;

    return db;
}

Tilemap *Initialization::InitTileMaps(Database *database){
    Tilemap *tm = new Tilemap(1);
    Color* c;

    int yVal = 0, xVal = 0;

    std::vector<TileInterface> tiles = database->getTile();
    std::cout << "Jumlah Tilese : " << tiles.size() << std::endl;

    for(int i = 0;i < tiles.size();i++){
        TileInterface t = tiles[i];

        RectangleBlock* bl = new RectangleBlock(
            c->hexToColor(t.color),
            t.width,
            t.height,
            t.x_position,
            t.y_position
        );

        tm->setTile(t.x_position == 0 ? 0 : t.x_position / 40, t.y_position == 0 ? 0 : t.y_position / 40, bl);
    }

    return tm;
}

std::vector<Sound*> Initialization::InitSounds(){
    std::vector<Sound*> sounds;

    Sound *vine_boom = new Sound("assets/sound/vine-boom.mp3", "vine-boom");
    sounds.push_back(vine_boom);

    return sounds;
}
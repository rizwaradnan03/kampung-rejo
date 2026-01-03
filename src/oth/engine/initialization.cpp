#include <oth/engine/initialization.hpp>
#include <oth/engine/database.hpp>
#include <oth/node/tilemap.hpp>
#include <string>

Database *Initialization::InitDatabase()
{
    Database *db = new Database("game.db");
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

    return db;
}

Tilemap *Initialization::InitTileMaps(){
    Tilemap *tm = new Tilemap(1);

    int yVal = 0, xVal = 0;
    while (yVal < 21)
    {
        while (xVal < 28)
        {
            RectangleBlock *bl = new RectangleBlock(
                sf::Color::Blue,
                40,
                40,
                xVal * 40,
                yVal * 40);

            tm->setTile(yVal, xVal, bl);
            xVal++;
        }

        xVal = 0;
        yVal++;
    }

    return tm;
}
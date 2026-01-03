#include <oth/engine/initialization.hpp>
#include <oth/engine/database.hpp>
#include <oth/node/tilemap.hpp>

Database *Initialization::InitDatabase(){
    Database *db = new Database("game.db");

    return db;
}

Tilemap *Initialization::InitTileMaps(){
    Tilemap *tm = new Tilemap(1);

    int yVal = 0, xVal = 0;
    while (yVal < 21){
        while (xVal < 28){
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
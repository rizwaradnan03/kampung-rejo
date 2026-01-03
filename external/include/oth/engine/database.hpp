#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <string>
#include <sqlite/sqlite3.h>
#include <interfaces/player.hpp>
#include <interfaces/tilemap.hpp>
#include <interfaces/tile.hpp>
#include <vector>

class Database {
    public:
        Database(const std::string &path);
        bool executeQuery(const std::string& sql);
        sqlite3* getDB();

        PlayerInterface getPlayer();
        std::vector<TilemapInterface> getTilemap();
        std::vector<TileInterface> getTile();

    private:
        sqlite3* db;
};

#endif
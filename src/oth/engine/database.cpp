#include <oth/engine/database.hpp>
#include <iostream>

Database::Database(const std::string &path){
    if(sqlite3_open(path.c_str(), &this->db)){
        std::cerr << "Failed open DB: " << sqlite3_errmsg(db) << std::endl;
        this->db = nullptr;
    }
}

bool Database::executeQuery(const std::string &sql){
    char* errMsg = nullptr;
    int rc = sqlite3_exec(this->db, sql.c_str(), nullptr, nullptr, &errMsg);
    
    if(rc != SQLITE_OK){
       std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false; 
    }

    return true;
}

sqlite3* Database::getDB() {
    return db;
}

std::vector<TilemapInterface> Database::getTilemap(){
    std::vector<TilemapInterface> tilemaps;

    const char* sql = "SELECT * FROM tilemaps;";
    sqlite3_stmt* stmt;

    if(sqlite3_prepare_v2(this->db, sql, -1, &stmt, nullptr) != SQLITE_OK){
        return tilemaps;
    }

    while(sqlite3_step(stmt) == SQLITE_ROW){
        TilemapInterface tilemap;
        tilemap.id = sqlite3_column_int(stmt, 0);
        tilemap.priority = sqlite3_column_int(stmt, 1);

        tilemaps.push_back(tilemap);
    }

    sqlite3_finalize(stmt);
    return tilemaps;
}

std::vector<TileInterface> Database::getTile(){
    std::vector<TileInterface> tiles;

    const char *sql = "SELECT * FROM tiles;";
    sqlite3_stmt *stmt;

    if(sqlite3_prepare_v2(this->db, sql, -1, &stmt, nullptr) != SQLITE_OK){
        return tiles;
    }

    while(sqlite3_step(stmt) == SQLITE_ROW){
        TileInterface tile;
        tile.id = sqlite3_column_int(stmt, 0);
        tile.tilemap_id = sqlite3_column_int(stmt, 1);
        tile.color = reinterpret_cast<const char*>(
            sqlite3_column_text(stmt, 2)
        );
        tile.width = static_cast<float>(sqlite3_column_double(stmt, 3));
        tile.height = static_cast<float>(sqlite3_column_double(stmt, 4));
        tile.x_position = sqlite3_column_int(stmt, 5);
        tile.y_position = sqlite3_column_int(stmt, 6);

        tiles.push_back(tile);
    }

    sqlite3_finalize(stmt);
    return tiles;
}
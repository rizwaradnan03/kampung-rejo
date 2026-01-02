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
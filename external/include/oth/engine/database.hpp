#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <string>
#include <sqlite/sqlite3.h>

class Database {
    public:
        Database(const std::string &path);
        bool executeQuery(const std::string& sql);

        sqlite3* getDB();

    private:
        sqlite3* db;
};

#endif
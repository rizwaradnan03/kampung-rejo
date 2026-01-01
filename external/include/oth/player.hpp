#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include <utility>

class Player {
public:
    void setName(const std::string& name);
    std::string getName() const;

    void setInventory(int id, int value);                // tambah / update item
    std::vector<std::pair<int,int>> getInventory() const; // ambil semua inventory
    std::pair<int,int> getSingleInventory(int id) const;  // ambil satu item
    void deleteInventory(int id);                       // hapus item
    void clearInventory();                               // hapus semua inventory

private:
    std::string name;
    std::vector<std::pair<int,int>> inventory;
};

#endif

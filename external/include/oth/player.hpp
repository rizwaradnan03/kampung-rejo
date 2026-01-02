#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include <utility>
#include <oth/render.hpp>
#include <oth/

class Player: public Render, public Physics {
public:
    void Init(const sf::Color& color, float width, float height);
    void setName(const std::string& name);
    std::string getName() const;

    void setInventory(int id, int value);                
    std::vector<std::pair<int,int>> getInventory() const;
    std::pair<int,int> getSingleInventory(int id) const;
    void deleteInventory(int id);
    void clearInventory();

    void Render();

private:
    std::string name;
    std::vector<std::pair<int,int>> inventory;
    sf::RectangleShape shape;
    std::float width;
    std::float height;
};

#endif

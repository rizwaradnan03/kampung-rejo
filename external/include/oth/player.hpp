#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include <utility>
#include <oth/render.hpp>
#include <oth/logic/physics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <oth/input.hpp>

class Player: public Render, public Physics, public InputHandling {
public:
    Player(const sf::Color& color, float width, float height);
    
    void setName(const std::string& name);
    std::string getName() const;

    void setInventory(int id, int value);                
    std::vector<std::pair<int,int>> getInventory() const;
    std::pair<int,int> getSingleInventory(int id) const;
    void deleteInventory(int id);
    void clearInventory();

    void shapeRender(sf::RenderWindow* window) override;
    void Handle(const sf::Event& event) override;

    void HandleCollision();

private:
    std::string id;
    std::string name;
    std::vector<std::pair<int,int>> inventory;
    sf::RectangleShape shape;
};

#endif

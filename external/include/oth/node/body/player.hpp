#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include <utility>
#include <oth/engine/render.hpp>
#include <oth/logic/physics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <oth/engine/input.hpp>
#include <oth/engine/database.hpp>

class Player: public Render, public Physics, public InputHandling {
public:
    Player(const sf::Color& color, float width, float height, Database *database);
    void Process(float dt, const sf::Event& event);
    void AnimatedSprite();

    void setName(const std::string& name);
    std::string getName() const;

    void setInventory(int id, int value);                
    std::vector<std::pair<int,int>> getInventory() const;
    std::pair<int,int> getSingleInventory(int id) const;
    void deleteInventory(int id);
    void clearInventory();

    void shapeRender(sf::RenderWindow* window) override;
    void InputHandle(float dt, const sf::Event& event) override;

    void HandleCollision();

    void setStateMovement(std::string movement);
    std::string getStateMovement();
    
    void setStateAction(std::string action);
    std::string getStateAction();

    void setIsMoving(bool im);
    bool getIsMoving();

    sf::Vector2f getPosition();

private:
    std::string id;
    std::string name;
    std::vector<std::pair<int,int>> inventory;
    Database *database;
    
    bool is_moving;
    
    std::string state_movement;
    std::string state_action;
    
    // shape justify the body it self and if AND IF STATE MOVEMENT WILL EXECUTE (LEG, BODY, TOP IT SELF)
    sf::RectangleShape shape;
    sf::RectangleShape leg;
    sf::Texture leg_texture;
    sf::RectangleShape body;
    sf::RectangleShape top;

    float elapsed_time;
};

#endif

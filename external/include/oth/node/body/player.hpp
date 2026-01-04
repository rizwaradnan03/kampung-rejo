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
    void Process(float dt);
    void animated_sprite();

    void setName(const std::string& name);
    std::string getName() const;

    void setInventory(int id, int value);                
    std::vector<std::pair<int,int>> getInventory() const;
    std::pair<int,int> getSingleInventory(int id) const;
    void deleteInventory(int id);
    void clearInventory();

    void _shape_render(sf::RenderWindow* window) override;
    void InputHandle(float dt, const sf::Event& event) override;

    void HandleCollision();

    void setStateMovement(std::string movement);
    std::string getStateMovement();
    
    void setStateAction(std::string action);
    std::string getStateAction();

    void setIsMoving(bool im);
    bool getIsMoving();

    void calculate_elapsed_time();

    sf::Vector2f getPosition();
    
    void set_movement_by_action(std::string action);

    void set_selected_move(int mv);
    int get_selected_move();

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
    
    sf::Texture movement_lists[2][6];
    int selected_move;

    sf::Clock clock;
    float elapsed_time;
};

#endif

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

    void set_name(const std::string& name);
    std::string get_name() const;

    void set_inventory(int id, int value);                
    std::vector<std::pair<int,int>> get_inventory() const;
    std::pair<int,int> get_single_inventory(int id) const;
    void delete_inventory(int id);
    void clear_inventory();

    void _shape_render(sf::RenderWindow* window) override;
    void _input_handle(float dt, const sf::Event& event) override;

    void HandleCollision();

    void set_state_movement(std::string movement);
    std::string get_state_movement();
    
    void set_state_action(std::string action);
    std::string get_state_action();

    void set_is_moving(bool im);
    bool get_is_moving();

    void calculate_elapsed_time();

    sf::Vector2f get_position();
    
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
    
    std::vector<sf::Texture> movement_lists;
    int selected_move;

    sf::Clock clock;
    float elapsed_time;
};

#endif

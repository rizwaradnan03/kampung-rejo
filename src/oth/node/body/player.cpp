#include <oth/node/body/player.hpp>
#include <algorithm>
#include <utility>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <oth/engine/database.hpp>
#include <string>
#include <vector>
#include <oth/engine/initialization.hpp>

int SPEED = 2000;

Player::Player(const sf::Color& color, float width, float height, Database *database){
    // base shape
    this->shape.setSize(sf::Vector2f(width, height));
    // this->shape.setFillColor(color);
    this->shape.setOrigin(sf::Vector2f(0, 0));
    this->shape.setPosition({0.f, 0.f});
    
    this->database = database;
    this->elapsed_time = 0.f;
    this->set_is_moving(false);
    this->state_movement = "idle_bottom";
    this->selected_move = 0; 
}

void Player::set_name(const std::string& name) {
    this->name = name;
}

std::string Player::get_name() const {
    return this->name;
}

std::vector<std::pair<int,int>> Player::get_inventory() const {
    return inventory;
}

std::pair<int,int> Player::get_single_inventory(int id) const {
    for (const auto& item : inventory) {
        if (item.first == id)
            return item;
    }
    return std::make_pair(0,0);
}

void Player::set_inventory(int id, int value) {
    for (auto& item : inventory) {
        if (item.first == id) {
            item.second += value;
            return;
        }
    }
    inventory.push_back(std::make_pair(id, value));
}

void Player::delete_inventory(int id) {
    inventory.erase(
        std::remove_if(inventory.begin(), inventory.end(),
                  [id](const std::pair<int,int>& item){ return item.first == id; }),
        inventory.end()
    );
}

void Player::clear_inventory() {
    inventory.clear();
}

void Player::set_selected_move(int mv){
    this->selected_move = mv;
}

int Player::get_selected_move(){
    return this->selected_move;
}

void Player::set_state_movement(std::string movement){
    this->state_movement = movement;
}

std::string Player::get_state_movement(){
    return this->state_movement;
}

void Player::set_state_action(std::string action){
    this->state_action = action;
}

std::string Player::get_state_action(){
    return this->state_action;
}

void Player::set_is_moving(bool mv){
    this->is_moving = mv;
}

bool Player::get_is_moving(){
    return this->is_moving;
}

sf::Vector2f Player::get_position(){
    return this->shape.getPosition();
}

// doing reset if last movement different by current movement
void Player::_input_handle(float dt, const sf::Event& event){
    if(event.is<sf::Event::KeyPressed>()){
        auto keyB = event.getIf<sf::Event::KeyPressed>()->code;
        sf::Vector2f currentPost = this->shape.getPosition();
        
        if(keyB == sf::Keyboard::Key::A || keyB == sf::Keyboard::Key::D || keyB == sf::Keyboard::Key::W || keyB == sf::Keyboard::Key::S){
            std::string mov = "walk_left";

            if(keyB == sf::Keyboard::Key::A){
                currentPost.x -= dt * SPEED;
                mov = "walk_left";
                
            }else if(keyB == sf::Keyboard::Key::D){
                currentPost.x += dt * SPEED;
                mov = "walk_right";
                
            }else if(keyB == sf::Keyboard::Key::W){
                currentPost.y -= dt * SPEED;
                mov = "walk_top";
                
            }else if(keyB == sf::Keyboard::Key::S){
                currentPost.y += dt * SPEED;
                mov = "walk_bottom";
            }
    
            // checking the last so do i need to refetch again?
            if(mov != this->get_state_movement()){
                // this->movement_lists = Initialization::get_movement_list_by_action(mov);

                this->elapsed_time = 0.f;
            }

            this->set_state_movement(mov);
            this->shape.setPosition(currentPost);
            this->set_is_moving(true);
        }else{
            this->set_is_moving(false);
        }
    }else if(event.is<sf::Event::KeyReleased>()){
        this->set_is_moving(false);
    }

    if(event.is<sf::Event::MouseButtonPressed>()){
        std::cout << this->get_state_movement() << std::endl;
    }
}

void Player::calculate_elapsed_time(){
    float delta_time = this->clock.restart().asSeconds();
    this->elapsed_time += delta_time;
}

void Player::_shape_render(sf::RenderWindow* window){
    // this->shape.setTexture(&this->movement_lists[this->selected_move][0]);
    window->draw(this->shape);
}

// to handle every movement from above function
// void Player::animated_sprite(){
//     // checking refetch sprite
//     std::string movChoose = "idle_bottom";
//     std::string stm = this->get_state_movement();

// }

void Player::Process(float dt){
    this->calculate_elapsed_time();
    // this->animated_sprite();
    // std::cout << "The Movement Lists !! : " << std::endl;
}
#include <oth/node/body/player.hpp>
#include <algorithm>
#include <utility>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <oth/engine/database.hpp>
#include <string>
#include <vector>
#include <oth/engine/initialization.hpp>
#include <oth/lib/get.hpp>
#include <cmath>

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

    this->moving_index = 0;

    this->preparation();
}

void Player::preparation(){
    std::vector<std::pair<std::string, std::vector<sf::Texture>>> mlists;
    int tl = 2;

    std::string txts[tl] = {
        {
            "idle_bottom"
        },
        {
            "idle_right"
        },
    };

    for(int i = 0;i < tl;i++){
        std::vector<sf::Texture> m;
        std::string stringified = "assets/player/" + txts[i];
        
        for(int j = 0;j < get_count_of_files_in_path(stringified);j++){
            std::string file_path = stringified + "/" + txts[i] + "_" + std::to_string(j+1) + ".png";

            m.emplace_back();
            if(!m[j].loadFromFile(file_path)){
                std::cout << "Failed To Load Texture!" << std::endl;
            }
        }

        std::pair<std::string, std::vector<sf::Texture>> lists = std::make_pair(txts[i], m);
        mlists.push_back(lists);
    }

    this->movement_lists = mlists;
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
    for(int i = 0;i < this->inventory.size();i++){
        if(this->inventory[i].first == id){
            return this->inventory[i];
        }
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

void Player::set_movement_by_action(std::string action){
    for(int i = 0;i < this->movement_lists.size();i++){
        std::pair<std::string, std::vector<sf::Texture>> ml = movement_lists[i];

        if(ml.first == action){
            this->set_movements(ml.second);
        }
    }
}

void Player::set_movements(std::vector<sf::Texture> mvs){
    this->movements = mvs;
}

std::vector<sf::Texture> Player::get_movements(){
    return this->movements;
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
    
            // i need to reset / refetch it again!!!
            if(mov != this->get_state_movement()){
                this->moving_index = 0;
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
    float for_every = 1 / this->movements.size();
    if(std::fmod(this->elapsed_time, for_every) == 0){
        int cl = this->elapsed_time / for_every;

        std::cout << "Me Gustas Tu : " << cl << std::endl;
    }

    window->draw(this->shape);
}

void Player::check_movement(){
    std::string mv = "ide_bottom";

    if(this->is_moving == false){
        
    }else{
        mv = this->state_movement;
    }
}

void Player::Process(float dt){
    this->check_movement();
    this->calculate_elapsed_time();
}
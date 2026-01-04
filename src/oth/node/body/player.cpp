#include <oth/node/body/player.hpp>
#include <algorithm>
#include <utility>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <oth/engine/database.hpp>
#include <string>
#include <vector>

int SPEED = 2000;

Player::Player(const sf::Color& color, float width, float height, Database *database){
    // base shape
    this->shape.setSize(sf::Vector2f(width, height));
    // this->shape.setFillColor(color);
    this->shape.setOrigin(sf::Vector2f(0, 0));
    this->shape.setPosition({0.f, 0.f});
    
    this->database = database;
    this->elapsed_time = 0.f;
    this->setIsMoving(false);
    this->state_movement = "idle_bottom";
    this->selected_move = 0; 

    std::string txts[2][2] = {
        {
            "idle_bottom",
            "idle_bottom"
        },
        {
            "idle_right",
            "idle_right"
        },
    };

    // initialize the texture
    for(int i = 0;i < 2;i++){
        std::vector<sf::Texture> mvs;

        for(int j = 0;j < 6;j++){
            std::string stringified = "assets/player/";
            if(i == 0){
                stringified += "idle_bottom/";
            }else if(i == 1){
                stringified += "idle_right/";
            }

            std::string strf = std::to_string(j+1);
            stringified += txts[i][0] + "_" + strf + ".png";
            
            if(!this->movement_lists[i][j].loadFromFile(stringified)){
                std::cout << "Failed To Load Texture!!" << std::endl;
            }
        }
    }
}

void Player::setName(const std::string& name) {
    this->name = name;
}

std::string Player::getName() const {
    return this->name;
}

std::vector<std::pair<int,int>> Player::getInventory() const {
    return inventory;
}

std::pair<int,int> Player::getSingleInventory(int id) const {
    for (const auto& item : inventory) {
        if (item.first == id)
            return item;
    }
    return std::make_pair(0,0);
}

void Player::setInventory(int id, int value) {
    for (auto& item : inventory) {
        if (item.first == id) {
            item.second += value;
            return;
        }
    }
    inventory.push_back(std::make_pair(id, value));
}

void Player::deleteInventory(int id) {
    inventory.erase(
        std::remove_if(inventory.begin(), inventory.end(),
                  [id](const std::pair<int,int>& item){ return item.first == id; }),
        inventory.end()
    );
}

void Player::clearInventory() {
    inventory.clear();
}

void Player::_shape_render(sf::RenderWindow* window){
    this->shape.setTexture(&this->movement_lists[this->selected_move][0]);
    window->draw(this->shape);
}

void Player::setStateMovement(std::string movement){
    this->state_movement = movement;
}

std::string Player::getStateMovement(){
    return this->state_movement;
}

void Player::setStateAction(std::string action){
    this->state_action = action;
}

std::string Player::getStateAction(){
    return this->state_action;
}

void Player::setIsMoving(bool mv){
    this->is_moving = mv;
}

bool Player::getIsMoving(){
    return this->is_moving;
}

sf::Vector2f Player::getPosition(){
    return this->shape.getPosition();
}

void Player::_input_handle(float dt, const sf::Event& event){
    if(event.is<sf::Event::KeyPressed>()){
        auto keyB = event.getIf<sf::Event::KeyPressed>()->code;
        sf::Vector2f currentPost = shape.getPosition();
        
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
            if(mov != this->getStateMovement()){
                this->elapsed_time = 0.f;
            }

            this->setStateMovement(mov);
            this->shape.setPosition(currentPost);
            this->setIsMoving(true);
        }else{
            this->setIsMoving(false);
        }
    }else if(event.is<sf::Event::KeyReleased>()){
        this->setIsMoving(false);
    }

    if(event.is<sf::Event::MouseButtonPressed>()){
        std::cout << this->getStateMovement() << std::endl;
    }
}

void Player::set_movement_by_action(std::string action){
    int index = 0;

    if(action == "idle_bottom"){
        index = 0;
    }else if(action == "idle_right"){
        index = 1;
    }

    this->set_selected_move(index);
}

// to handle every movement from above function
void Player::animated_sprite(){
    // checking refetch sprite
    std::string movChoose = "idle_bottom";
    std::string stm = this->getStateMovement();

    if(this->is_moving == false){
        if(stm == "walk_bottom"){
            movChoose = "idle_bottom";
        }else if(stm == "walk_top"){
            movChoose = "idle_top";
        }else if(stm == "walk_right"){
            movChoose = "idle_right";
        }else if(stm == "walk_left"){
            movChoose = "idle_left";
        }
    }else{
        movChoose = stm;
    }

    this->set_movement_by_action(movChoose);
}

void Player::calculate_elapsed_time(){
    float delta_time = this->clock.restart().asSeconds();
    this->elapsed_time += delta_time;
}

void Player::set_selected_move(int mv){
    this->selected_move = mv;
}

int Player::get_selected_move(){
    return this->selected_move;
}

void Player::Process(float dt){
    this->calculate_elapsed_time();
    this->animated_sprite();
}
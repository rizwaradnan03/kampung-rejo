#include <oth/node/body/player.hpp>
#include <algorithm>
#include <utility>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <oth/engine/database.hpp>

int SPEED = 2000;

Player::Player(const sf::Color& color, float width, float height, Database *database){
    // base shape
    this->shape.setSize(sf::Vector2f(width, height));
    this->shape.setFillColor(color);
    this->shape.setOrigin(sf::Vector2f(0, 0));
    this->shape.setPosition({0.f, 0.f});

    if(!this->leg_texture.loadFromFile("assets/accessories/default/idle_default_bottom.png")){
        std::cout << "Failed Load Texture!!" << std::endl;
    }

    this->leg.setSize(sf::Vector2f(width, height));
    this->leg.setTexture(&this->leg_texture);
    this->leg.setOrigin(sf::Vector2f(0, -5));

    this->database = database;
    this->elapsed_time = 0.f;
    this->setIsMoving(false);
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

void Player::shapeRender(sf::RenderWindow* window){
    window->draw(this->shape);
    window->draw(this->leg);
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

void Player::InputHandle(float dt, const sf::Event& event){
    if(event.is<sf::Event::KeyPressed>()){
        auto keyB = event.getIf<sf::Event::KeyPressed>()->code;
        sf::Vector2f currentPost = shape.getPosition();

        if(keyB == sf::Keyboard::Key::A){
            currentPost.x -= dt * SPEED;
            this->setStateMovement("walk_left");

        }else if(keyB == sf::Keyboard::Key::D){
            currentPost.x += dt * SPEED;
            this->setStateMovement("walk_right");
            
        }else if(keyB == sf::Keyboard::Key::W){
            currentPost.y -= dt * SPEED;
            this->setStateMovement("walk_top");
            
        }else if(keyB == sf::Keyboard::Key::S){
            currentPost.y += dt * SPEED;
            this->setStateMovement("walk_bottom");
        }

        this->shape.setPosition(currentPost);
        this->setIsMoving(true);
    }else if(event.is<sf::Event::KeyReleased>()){
        this->setIsMoving(false);
    }

    if(event.is<sf::Event::MouseButtonPressed>()){
        std::cout << this->getStateMovement() << std::endl;
    }
}

void Player::AnimatedSprite(){

}

void Player::calculate_elapsed_time(){
    float delta_time = this->clock.restart().asSeconds();
    elapsed_time += delta_time;

    std::cout << "Delta Time : " << elapsed_time << std::endl;
}

void Player::Process(float dt){
    this->calculate_elapsed_time();
    this->AnimatedSprite();
}
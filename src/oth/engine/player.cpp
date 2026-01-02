#include <oth/engine/player.hpp>
#include <algorithm>
#include <utility>
#include <SFML/Graphics.hpp>
#include <iostream>

int SPEED = 2000;

Player::Player(const sf::Color& color, float width, float height){
    this->shape.setSize(sf::Vector2f(width, height));
    this->shape.setFillColor(color);

    this->shape.setOrigin(sf::Vector2f(width / 2.f, height / 2.f));
    this->shape.setPosition({0.f, 0.f});
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
}

void Player::InputHandle(float dt, const sf::Event& event){
    if(event.is<sf::Event::KeyPressed>()){
        auto keyB = event.getIf<sf::Event::KeyPressed>()->code;
        sf::Vector2f currentPost = shape.getPosition();

        if(keyB == sf::Keyboard::Key::A){
            currentPost.x -= dt * SPEED;
        }else if(keyB == sf::Keyboard::Key::D){
            currentPost.x += dt * SPEED;
        }else if(keyB == sf::Keyboard::Key::W){
            currentPost.y -= dt * SPEED;
        }else if(keyB == sf::Keyboard::Key::S){
            currentPost.y += dt * SPEED;
        }

        this->shape.setPosition(currentPost);
    }

    if(event.is<sf::Event::MouseButtonPressed>()){
        std::cout << "Mouse Button Pressed" << std::endl;
    }

}

void Player::Process(float dt, const sf::Event& event){
    this->InputHandle(dt, event);
}
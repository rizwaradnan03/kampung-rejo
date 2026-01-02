#include <oth/player.hpp>
#include <algorithm>
#include <utility>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int speed = 10;

Player::Player(const sf::Color& color, float width, float height){
    this->shape.setSize(sf::Vector2f(width, height));
    this->shape.setFillColor(color);

    this->shape.setOrigin(sf::Vector2f(width / 2.f, height / 2.f));
    this->shape.setPosition({0.f, 0.f});
}

void Player::setName(const string& name) {
    this->name = name;
}

string Player::getName() const {
    return this->name;
}

vector<pair<int,int>> Player::getInventory() const {
    return inventory;
}

pair<int,int> Player::getSingleInventory(int id) const {
    for (const auto& item : inventory) {
        if (item.first == id)
            return item;
    }
    return make_pair(0,0);
}

void Player::setInventory(int id, int value) {
    for (auto& item : inventory) {
        if (item.first == id) {
            item.second += value;
            return;
        }
    }
    inventory.push_back(make_pair(id, value));
}

void Player::deleteInventory(int id) {
    inventory.erase(
        remove_if(inventory.begin(), inventory.end(),
                  [id](const pair<int,int>& item){ return item.first == id; }),
        inventory.end()
    );
}

void Player::clearInventory() {
    inventory.clear();
}

void Player::shapeRender(sf::RenderWindow* window){
    window->draw(this->shape);
}

void Player::Handle(const sf::Event& event){
    if(event.is<sf::Event::KeyPressed>()){
        auto keyB = event.getIf<sf::Event::KeyPressed>()->code;
        sf::Vector2f currentPost = shape.getPosition();

        if(keyB == sf::Keyboard::Key::A){
            currentPost.x -= speed;
        }else if(keyB == sf::Keyboard::Key::D){
            currentPost.x += speed;
        }else if(keyB == sf::Keyboard::Key::W){
            currentPost.y -= speed;
        }else if(keyB == sf::Keyboard::Key::S){
            currentPost.y += speed;
        }

        this->shape.setPosition(currentPost);
    }

    if(event.is<sf::Event::MouseButtonPressed>()){
        std::cout << "Mouse Button Pressed" << std::endl;
    }

}
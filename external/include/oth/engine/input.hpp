#pragma once

#include <SFML/Window/Event.hpp>

class InputHandling {
    public:
        virtual void InputHandle(float dt, const sf::Event& event) = 0;
};

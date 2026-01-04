#pragma once

#include <SFML/Window/Event.hpp>

class InputHandling {
    public:
        virtual void _input_handle(float dt, const sf::Event& event) = 0;
};

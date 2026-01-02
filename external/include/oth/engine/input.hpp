#pragma once

#include <SFML/Window/Event.hpp>

class InputHandling {
    public:
        virtual void Handle(const sf::Event& event) = 0;
};

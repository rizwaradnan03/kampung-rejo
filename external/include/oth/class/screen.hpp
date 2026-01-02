#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <oth/render.hpp>
#include <vector>

class Screen {
    public:
        std::vector<Render> getAllObject();
    
    private:
        std::vector<Render> obj;
};

#endif
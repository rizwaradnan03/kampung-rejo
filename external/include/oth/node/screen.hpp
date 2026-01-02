#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <oth/engine/render.hpp>
#include <vector>

class Screen {
    public:
        std::vector<Render*> getAllObject();
        void setObject(Render* object);
    private:
        std::vector<Render*> obj;
};

#endif
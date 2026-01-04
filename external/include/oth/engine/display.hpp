#pragma once

class Display {
    public:
        void setWidth(int w);
        void setHeight(int h);

    private:
        unsigned int width = 1920;
        unsigned int height = 1080;
};
#ifndef TILE_INTERFACE_HPP
#define TILE_INTERFACE_HPP

#include <string>
#include <utility>

struct TileInterface{
    int id;
    int tilemap_id;
    std::string color;
    float width;
    float height;
    int x_position;
    int y_position;
};


#endif
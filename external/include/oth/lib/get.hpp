#ifndef GET_HPP
#define GET_HPP

#include <oth/node/tilemap.hpp>
#include <vector>

Tilemap* getTilemapByPriority(int wp, std::vector<Tilemap*> &tms);

#endif
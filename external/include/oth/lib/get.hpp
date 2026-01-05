#ifndef GET_HPP
#define GET_HPP

#include <oth/node/tilemap.hpp>
#include <vector>
#include <filesystem>
#include <string>

Tilemap* getTilemapByPriority(int wp, std::vector<Tilemap*> &tms);

int get_count_of_files_in_path(std::string path);

#endif
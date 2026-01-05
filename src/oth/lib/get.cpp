#include <oth/lib/get.hpp>

Tilemap *getTilemapByPriority(int wp, std::vector<Tilemap *> &tms)
{
    for (int i = 0; i < tms.size(); i++)
    {
        Tilemap *t = tms[i];

        if (t->getPriority() == wp)
        {
            return t;
        }
    }

    return tms[0];
}

int get_count_of_files_in_path(std::string path){
    int c = 0;

    for (const auto &entry : std::filesystem::directory_iterator(path)){
        if (entry.is_regular_file()){
            c++;
        }
    }

    return c;
}
#include <oth/lib/get.hpp>

Tilemap* getTilemapByPriority(int wp, std::vector<Tilemap*> &tms){
    for(int i = 0;i < tms.size();i++){
        Tilemap* t = tms[i];

        if(t->getPriority() == wp){
            return t;
        }
    }

    return tms[0];
}
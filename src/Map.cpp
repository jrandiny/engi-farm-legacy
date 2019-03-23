#include <Map.h>

Map::Map(int _width,int _height):width(_width),height(_height){
    map.resize(height);

    for(int i=0;i<width;i++){
        map[i].resize(width);
    }
}

std::vector<std::shared_ptr<Cell>> Map::getSurrounding(int x, int y) {
    std::vector<std::shared_ptr<Cell>> temp;

    if(y>0){ // up
        temp.push_back(map[y-1][x]);
    }else{
        temp.push_back(nullptr);
    }

    if(x+1<width){ // right
        temp.push_back(map[y][x+1]);
    }else{
        temp.push_back(nullptr);
    }

    if(y+1<height){ // down
        temp.push_back(map[y+1][x]);
    }else{
        temp.push_back(nullptr);
    }

    if(x>0){ // left 
        temp.push_back(map[y][x-1]);
    }else{
        temp.push_back(nullptr);
    }

    temp.push_back(map[y][x]); // posisi sekrang

    return temp;
}

std::shared_ptr<Mixer> Map::getMixer(int x, int y){
    bool found = false;
    std::vector<std::shared_ptr<Mixer>>::iterator it = mixer.begin();
    while(it!=mixer.end() && !found){
        if ((*it)->getX()==x && (*it)->getY()==y){
            found = true;
        }
        else {
            it++;
        }
    }
    if (found){
        return *it;
    } else {
        throw std::runtime_error("No Mixer Found");
    }
}

std::shared_ptr<Truck> Map::getTruck(int x, int y) {
    bool found = false;
    std::vector<std::shared_ptr<Truck>>::iterator it = truck.begin();
    while(it!=truck.end() && !found){
        if ((*it)->getX()==x && (*it)->getY()==y){
            found = true;
        }
        else {
            it++;
        }
    }
    if (found){
        return *it;
    } else {
        throw std::runtime_error("No Truck Found");
    }
}

std::shared_ptr<Well> Map::getWell(int x, int y) {
    bool found = false;
    std::vector<std::shared_ptr<Well>>::iterator it = well.begin();
    while(it!=well.end() && !found){
        if ((*it)->getX()==x && (*it)->getY()==y){
            found = true;
        }
        else {
            it++;
        }
    }
    if (found){
        return *it;
    } else {
        throw std::runtime_error("No Well Found");
    }
}

std::shared_ptr<FarmAnimal> Map::getFarmAnimal(int x, int y) {
    bool found = false;
    std::vector<std::shared_ptr<FarmAnimal>>::iterator it = farmAnimal.begin();
    while(it!=farmAnimal.end() && !found){
        if ((*it)->getX()==x && (*it)->getY()==y){
            found = true;
        }
        else {
            it++;
        }
    }
    if (found){
        return *it;
    } else {
        throw std::runtime_error("No Animal Found");
    }
}

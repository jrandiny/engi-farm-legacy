#include <Map.h>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <algorithm>
#include <memory>
#include <Cell/Land/Coop.h>
#include <Cell/Land/Barn.h>
#include <Cell/Land/GrassLand.h>
#include <FarmAnimal/FarmAnimal.h>
#include <FarmAnimal/Chicken.h>
#include <FarmAnimal/Duck.h>
#include <FarmAnimal/Cow.h>
#include <FarmAnimal/Goat.h>
#include <FarmAnimal/Horse.h>
#include <FarmAnimal/Rabbit.h>

Map::Map(int _width,int _height):width(_width),height(_height){
    int x, y;
    // int type;
    bool horizon;
    const int divider = 3;
    const int minimum_Animal = 2;
    std::vector<Cell::CellType> urutan;
    srand (time(NULL));
    map.resize(height);
    for(int i=0;i<width;i++){
        map[i].resize(width);
    }
    //random bool
    horizon = rand()%2;
    x = rand()%(_width/2)+(_width/4);
    y = rand()%(_height/2)+(_height/4);
    urutan.push_back(Cell::BarnType);
    urutan.push_back(Cell::CoopType);
    urutan.push_back(Cell::GrassLandType);
    std::random_shuffle(urutan.begin(),urutan.end());
    int luas;

    setCellMap(0,0,x,y,urutan[0]);
    luas = (x+1)*(y+1);
    randomAnimalMap(0,0,x,y,urutan[0],rand()%(luas/divider)+minimum_Animal);
    if(horizon){
        setCellMap(0,y+1,_width-1,_height-1,urutan[1]);
        setCellMap(x+1,0,_width-1,y,urutan[2]);
        luas = (_width)*(_height-y-1);
        randomAnimalMap(0,y+1,_width-1,_height-1,urutan[1],rand()%(luas/divider)+minimum_Animal);
        luas = (_width-x-1)*(y+1);
        randomAnimalMap(x+1,0,_width-1,y,urutan[2],rand()%(luas/divider)+minimum_Animal);
    } else {
        setCellMap(0,y+1,x,_height-1,urutan[1]);
        setCellMap(x+1,0,_width-1,_height-1,urutan[2]);
        luas = (x+1)*(_height-y-1);
        randomAnimalMap(0,y+1,x,_height-1,urutan[1],rand()%(luas/divider)+minimum_Animal);
        luas = (_width-x-1)*(_height);
        randomAnimalMap(x+1,0,_width-1,_height-1,urutan[2],rand()%(luas/divider)+minimum_Animal);
    }
}

void Map::randomAnimalMap(int xFrom, int yFrom, int xTo, int yTo, Cell::CellType type, int jumlahHewan){
    int count = 0;
    int chance;

    while(count<jumlahHewan){
        int i = rand()%(xTo-xFrom+1)+xFrom;
        int j = rand()%(yTo-yFrom+1)+yFrom;
        if(!map[j][i]->isOccupied()){
            switch(type){
                case Cell::CoopType:
                    chance = rand()%2;
                    if(chance==1){
                        farmAnimal.push_back(std::shared_ptr<FarmAnimal>(new Chicken(i,j)));
                    }else{
                        farmAnimal.push_back(std::shared_ptr<FarmAnimal>(new Duck(i,j)));
                    }
                    break;
                case Cell::BarnType:
                    chance = rand()%4;
                    if(chance==1){
                        farmAnimal.push_back(std::shared_ptr<FarmAnimal>(new Cow(i,j,type)));
                    }else if(chance==2){
                        farmAnimal.push_back(std::shared_ptr<FarmAnimal>(new Goat(i,j,type)));
                    }else if(chance==3){
                        farmAnimal.push_back(std::shared_ptr<FarmAnimal>(new Horse(i,j)));
                    }else{
                        farmAnimal.push_back(std::shared_ptr<FarmAnimal>(new Rabbit(i,j)));
                    }
                    break;
                case Cell::GrassLandType:
                    chance = rand()%2;
                    if(chance==1){
                        farmAnimal.push_back(std::shared_ptr<FarmAnimal>(new Cow(i,j,type)));
                    }else{
                        farmAnimal.push_back(std::shared_ptr<FarmAnimal>(new Goat(i,j,type)));
                    }
                    break;
            }
            std::shared_ptr<Land> temp = std::static_pointer_cast<Land>(map[j][i]);
            temp->occupy();
            count++;
        }
    }
}

void Map::setCellMap(int xFrom, int yFrom, int xTo, int yTo, Cell::CellType type){
    int grass = rand()%5;
    for(int j=yFrom;j<=yTo;j++){
        for(int i=xFrom;i<=xTo;i++){
            switch(type){
                case Cell::CoopType: 
                    map[j][i] = std::shared_ptr<Cell>(new Coop(i,j));
                    break;
                case Cell::BarnType:
                    map[j][i] = std::shared_ptr<Cell>(new Barn(i,j));
                    break;
                case Cell::GrassLandType:
                    map[j][i] = std::shared_ptr<Cell>(new GrassLand(i,j));
                    break;
            }
            if(grass>3){
                std::shared_ptr<Land> temp = std::static_pointer_cast<Land>(map[j][i]);
                temp->addGrass();
            }

        }
    }
}

void Map::setMap(std::vector<std::vector<std::shared_ptr<Cell>>> in){
    map = in;
}

std::vector<std::vector<std::shared_ptr<Cell>>> Map::getMap() const{
    return map;
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

std::vector<std::shared_ptr<FarmAnimal>> Map::getAllFarmAnimal() const{
    return farmAnimal;
}

std::vector<std::shared_ptr<FarmAnimal>> Map::getSurroundAnimal(int x, int y){
    bool found=false;
    std::vector<std::shared_ptr<FarmAnimal>> temp;

    std::vector<int> deltaX = {1,0,-1,0};
    std::vector<int> deltaY = {0,1,0,-1};
    
    for(int i=0;i<4;i++){
        int checkX = x+deltaX[i];
        int checkY = y+deltaY[i];
        
        try{
            temp.push_back(getFarmAnimal(checkX,checkY));
        }catch(const std::runtime_error e){
            
        }
        
    }
    return temp;
}

void Map::moveAllAnimal(){
    for(int i=0;i<farmAnimal.size();i++){
        if(farmAnimal[i]->getDeathStatus()){
            std::shared_ptr<Land> temp = std::static_pointer_cast<Land>(map[farmAnimal[i]->getY()][farmAnimal[i]->getX()]);
            temp->unoccupy();
            farmAnimal.erase(i+farmAnimal.begin());
        } else {
            std::vector<std::shared_ptr<Cell>> temp = getSurrounding(farmAnimal[i]->getX(),farmAnimal[i]->getY());
            farmAnimal[i]->moveRandom(temp);
            farmAnimal[i]->tick();
        }
    }
}
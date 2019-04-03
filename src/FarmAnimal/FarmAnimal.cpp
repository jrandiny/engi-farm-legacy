/**
 * @file Product.cpp
 * @author Back End K3
 * @brief file berisi implementasi kelas FarmAnimal
 * @version 0.1
 * @date 2019-03-01
 */

#include <FarmAnimal/FarmAnimal.h>
#include <cstdlib>
#include <ctime>
#include <Cell/Land.h>
#include <memory>

FarmAnimal::FarmAnimal(int x, int y, int time,Cell::CellType type):timeToHungry(time),habitat(type){
    posX = x;
    posY = y;
    setAndActivate(timeToHungry);
    eatStatus=true;
    deathStatus = false;
}

void FarmAnimal::setEatStatus(bool newStatus){
    eatStatus=newStatus;
    if(eatStatus){
        setAndActivate(timeToHungry);
    } else {
        setAndActivate(timeToDeath);
    }
}

bool FarmAnimal::getEatStatus(){
    return eatStatus;
}

void FarmAnimal::setDeathStatus(bool newStatus){
    deathStatus=newStatus;
    if(deathStatus){
        deactivateTimer();
    } else {
        setEatStatus(true);
    }
}

bool FarmAnimal::getDeathStatus(){
    return deathStatus;
}

void FarmAnimal::moveRandom(std::vector<std::shared_ptr<Cell>> sekitar){
    std::srand(std::time(nullptr));
    bool found = false;
    int count=0;
    int way;
    int posNow = 4;

    // coba gerak
    while (!found && count <4){
        way = std::rand()%4; 
        if(sekitar[way]!=nullptr){
            if(!sekitar[way]->isOccupied() && sekitar[way]->getType()==habitat){
                found = true;
            } else {
                count++;
            }
        } else {
            count++;
        }
    }

    std::shared_ptr<Land> now = std::static_pointer_cast<Land>(sekitar[posNow]); // land sekarang
    
    if(found){
        if(count<4){ // pindah
            std::shared_ptr<Land> go = std::static_pointer_cast<Land>(sekitar[way]); // land yang dituju
            now->unoccupy();
            go->occupy();
            switch (way)
            {
                case 0: // up
                    posY--;
                    break;
                case 1: // right
                    posX++;
                    break;
                case 2: // down
                    posY++;
                    break;
                case 3: // left
                    posX--;
                    break;
                default:
                    break;
            }
            now = go;
        }
    }

    // makan
    if(!eatStatus && now->haveGrass()){
        eatStatus= true;
        now->removeGrass();
    }

}

int FarmAnimal::getHabitat(){
    return habitat;
}

void FarmAnimal::callback(){
    if(eatStatus){
        eatStatus = false;
        setAndActivate(timeToDeath);
    }else{
        deathStatus = true;
    }
}

int FarmAnimal::getX() const{
    return posX;
}

int FarmAnimal::getY() const{
    return posY;
}
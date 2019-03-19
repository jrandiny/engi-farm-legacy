#include <FarmAnimal/FarmAnimal.h>

/**
 * @brief Konstruktor FarmAnimal dengan parameter timetohungry
 * 
 * @param time Waktu hingga lapar
 */
FarmAnimal::FarmAnimal(int time,int type):timeToHungry(time),habitat(type){
}

void FarmAnimal::setEatStatus(bool newStatus){
    eatStatus=newStatus;
}

bool FarmAnimal::getEatStatus(){
    return eatStatus;
}

void FarmAnimal::setDeathStatus(bool newStatus){
    deathStatus=newStatus;
}

bool FarmAnimal::getDeathStatus(){
    return deathStatus;
}

void FarmAnimal::moveRandom(){

}

int FarmAnimal::getHabitat(){
    return habitat;
}

void FarmAnimal::callback(){
    if(eatStatus){
        eatStatus = false;
        setTimer(timeToDeath);
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
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

void FarmAnimal::moveRandom(){

}

int FarmAnimal::getHabitat(){
    return habitat;
}
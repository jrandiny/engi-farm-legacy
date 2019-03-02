/**
 * @file Land.cpp
 * @author Back End K3
 * @brief File berisi implementasi kelas Land
 * @version 0.1
 * @date 2019-03-01
 */

#include <Cell/Land.h>

Land::Land(int _x, int _y, int _type):Cell(_x,_y),type(_type){
    grass = false;
};

int Land::getType() const{
    return type;
}

bool Land::haveGrass() const{
    return grass;
}

void Land::removeGrass(){
    grass = false;
}

void Land::addGrass(){
    grass = true;
}

void Land::occupy(){
    occupied = true;
}

void Land::unoccupy(){
    occupied = false;
}
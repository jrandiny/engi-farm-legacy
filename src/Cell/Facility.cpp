/**
 * @file Facility.cpp
 * @author Back End K3
 * @brief File untuk implementasi kelas Facility
 * @version 0.1
 * @date 2019-03-01
 */

#include <Cell/Facility.h>

Facility::Facility(int _x, int _y, CellType _type):Cell(_x,_y,_type){
    occupied = true;
}

bool Facility::isUsable() const{
    return usable;
}
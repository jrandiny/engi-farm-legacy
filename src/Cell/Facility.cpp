/**
 * @file Facility.cpp
 * @author Back End K3
 * @brief File untuk implementasi class Facility
 * @version 0.1
 * @date 2019-03-01
 */

#include <Cell/Facility.h>

/**
 * @brief Konstruktor objek facility
 * 
 * @param _x lokasi x
 * @param _y lokasi y
 */
Facility::Facility(int _x, int _y):Cell(_x,_y){
    occupied = true;
}

bool Facility::isUsable() const{
    return usable;
}
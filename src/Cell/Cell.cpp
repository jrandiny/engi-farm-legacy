/**
 * @file Cell.cpp
 * @author Back End K3
 * @brief File berisi implementasi kelas Cell
 * @version 0.1
 * @date 2019-03-01
 */
#include <Cell/Cell.h>

/**
 * @brief Konstruktor Cell
 * 
 * @param _x Lokasi X
 * @param _y Lokasi Y
 */
Cell::Cell(int _x, int _y, int _type):x(_x),y(_y),type(_type){}

/**
 * @brief Mengembalikan apakah terisi
 * 
 * @return Apakah Cell terisi
 */
bool Cell::isOccupied() const{
    return occupied;
}

int Cell::getType() const{
    return type;
}

/**
 * @brief Mengembalikan lokasi X
 * 
 * @return Lokasi X
 */
int Cell::getX() const{
    return x;
}

/**
 * @brief Mengembalikan lokasi Y
 * 
 * @return Lokasi y
 */
int Cell::getY() const{
    return y;
}

bool Cell::operator==(Cell& in){
    return in.getType()==getType();
}


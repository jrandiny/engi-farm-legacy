/**
 * @file Cell.cpp
 * @author Back End K3
 * @brief File berisi implementasi kelas Cell
 * @version 0.1
 * @date 2019-03-01
 */
#include <Cell/Cell.h>


Cell::Cell(int _x, int _y, int _type):x(_x),y(_y),type(_type){}


bool Cell::isOccupied() const{
    return occupied;
}

int Cell::getType() const{
    return type;
}


int Cell::getX() const{
    return x;
}

int Cell::getY() const{
    return y;
}

bool Cell::operator==(Cell& in){
    return in.getType()==getType();
}


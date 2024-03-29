/**
 * @file GrassLand.cpp
 * @author Back End K3
 * @brief File berisi implementasi kelas GrassLand
 * @version 0.1
 * @date 2019-03-02
 */

#include <Cell/Cell.h>
#include <Cell/Land/GrassLand.h>

GrassLand::GrassLand(int _x, int _y):Land(_x, _y, CellType::GrassLandType){}

std::string GrassLand::render(){
    if(haveGrass()){
        return "#"; //TODO
    }else{
        return "-";
    }
}

short GrassLand::getFgColor(){
    return 2;
}
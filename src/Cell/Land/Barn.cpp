/**
 * @file Barn.cpp
 * @author Back End K3
 * @brief File berisi implementasi kelas Barn
 * @version 0.1
 * @date 2019-03-02
 */

#include <Cell/Cell.h>
#include <Cell/Land/Barn.h>

Barn::Barn(int _x, int _y):Land(_x, _y,CellType::BarnType){}

std::string Barn::render(){
    if(haveGrass()){
        return "@"; //TODO
    }else{
        return "x";
    }
}
/**
 * @file Coop.cpp
 * @author Back End K3
 * @brief File berisi implementasi kelas Coop
 * @version 0.1
 * @date 2019-03-02
 */

#include <Cell/Land/Coop.h>

Coop::Coop(int _x, int _y):Land(_x, _y, 2){};

std::string Coop::render(){
    if(haveGrass()){
        return "*"; //TODO
    }else{
        return "o";
    }
}
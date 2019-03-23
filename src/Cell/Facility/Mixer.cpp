/**
 * @file Product.cpp
 * @author Back End K3
 * @brief file berisi implementasi kelas Mixer
 * @version 0.1
 * @date 2019-03-01
 */

#include <Cell/Facility/Mixer.h>
#include <Cell/Cell.h>

Mixer::Mixer(int _x, int _y):Facility(_x,_y,CellType::MixerType){

    usable = true;
}

std::string Mixer::render(){
    return "M";
}
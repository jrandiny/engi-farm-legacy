/**
 * @file Product.cpp
 * @author Back End K3
 * @brief file berisi implementasi kelas Truck
 * @version 0.1
 * @date 2019-03-01
 */

#include <Cell/Facility/Truck.h>
#include <Cell/Cell.h>
#include <TimerObject.h>

Truck::Truck(int _x, int _y):Facility(_x,_y,CellType::TruckType){
    usable = true;
}

void Truck::callback(){
    usable = true;
    deactivateTimer();
}

void Truck::use(int time){
    usable = false;
    setAndActivate(time);
}

std::string Truck::render(){
    return "D";
}
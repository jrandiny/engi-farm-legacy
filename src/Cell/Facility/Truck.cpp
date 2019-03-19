#include <Cell/Facility/Truck.h>
#include <TimerObject.h>

Truck::Truck(int _x, int _y):Facility(_x,_y,5){
    usable = false;
}

void Truck::callback(){
    usable = true;
    deactivateTimer();
}

std::string Truck::render(){
    return "D";
}
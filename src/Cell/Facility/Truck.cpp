#include <Cell/Facility/Truck.h>
#include <TimerObject.h>

Truck::Truck(int _x, int _y):Facility(_x,_y,Trck){
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
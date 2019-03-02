#include <SimulationObject.h>

SimulationObject::SimulationObject(){
    timerActive = false;
}
void SimulationObject::tick(){
    if(timerActive){
        if (timer>0){
            timer--;
        }else{
            callback();
            timerActive = false;
        }
    }
    
}
void SimulationObject::activateTimer(){
    timerActive = true;
}
void SimulationObject::deactivateTimer(){
    timerActive = false;
}
void SimulationObject::setTimer(int timer){
    this->timer = timer;
}

void SimulationObject::setAndActivate(int timer){
    setTimer(timer);
    activateTimer();
}
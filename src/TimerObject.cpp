#include <TimerObject.h>

TimerObject::TimerObject(){
    timerActive = false;
}
void TimerObject::tick(){
    if(timerActive){
        if (timer>0){
            timer--;
        }else{
            timerActive = false;
            callback();
        }
    }
    
}
void TimerObject::activateTimer(){
    timerActive = true;
}
void TimerObject::deactivateTimer(){
    timerActive = false;
}
void TimerObject::setTimer(int timer){
    this->timer = timer;
}

void TimerObject::setAndActivate(int timer){
    setTimer(timer);
    activateTimer();
}
#include <SimulationObject.h>
#include <Cell/Facility/Truck.h>
#include <Cell/Facility/Well.h>
#include <vector>
#include <iostream>

int main(){
    std::vector<Facility*> lof;
    std::vector<SimulationObject*> los;

    Truck* test = new Truck(0,0);

    lof.push_back(test);
    los.push_back(test);
    lof.push_back(new Well(10,10));

    int loop = 0;

    while(loop<10){
        for(Facility* fal : lof){
            std::cout<<"Fal "<<(*fal).getX()<<" u ="<<fal->isUsable()<<std::endl;
        }

        for(SimulationObject* sim : los){
            sim->tick();
            if(loop==1){
                sim->setTimer(3);
                sim->activateTimer();
            }
        }

        

        std::cout<<"new tick"<<std::endl;
        loop++;
    }


}
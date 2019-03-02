/**
 * @file SimulationObject.h
 * @author Back End K3
 * @brief File berisi definisi kelas Simulation Object
 * @version 0.1
 * @date 2019-03-01
 */


#ifndef SIMULATIONOBJ_H
#define SIMULATIONOBJ_H

/**
 * @brief Kelas abstrak SimulationObject
 * @class SimulationObject SimulationObject.h <SimulationObject.h>
 * 
 * Kelas ini adalah parent dari kelas Truck dan FarmAnimal
 * SimulationOject membuat object yang memiliki timer
 */
class SimulationObject{
    public:
        /**
         * @brief constructor object SimulationObject
         * 
         */
        SimulationObject();
        void tick();
        void activateTimer();
        void deactivateTimer();
        void setTimer(int timer);
        void setAndActivate(int timer);

    protected:
        virtual void callback()=0;

    private:
        bool timerActive;
        int timer;
};


#endif
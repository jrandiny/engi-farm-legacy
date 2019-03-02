/**
 * @file Truck.h
 * @author Back End K3
 * @brief File definisi class Truck
 * @version 0.1
 * @date 2019-03-01
 */
#ifndef TRUCK_H
#define TRUCK_H

#include <Cell/Facility.h>
#include <SimulationObject.h>

/**
 * @brief Kelas Fasilitas Truck
 * @class Truck Truck.h <Cell/Facility/Truck.h>
 * 
 * Kelas ini adalah kelas untuk fasilitas tipe Truck
 * Truck berguna untuk mengirim hasil dagangan
 */
class Truck:public Facility, public SimulationObject{
    public:
        /**
         * @brief Konstruktor Truck dengan parameter
         * 
         * @param _x Lokasi X
         * @param _y Lokasi Y
         */
        Truck(int _x, int _y);
    private:
        void callback();
};
#endif
/**
 * @file Truck.h
 * @author Back End K3
 * @brief File berisi definisi class Truck
 * @version 0.1
 * @date 2019-03-01
 */
#ifndef TRUCK_H
#define TRUCK_H

#include <Cell/Facility.h>
#include <TimerObject.h>

/**
 * @brief Kelas riil turunan Facility dan TimerObject
 * @class Truck Truck.h <Cell/Facility/Truck.h>
 * 
 * Kelas ini adalah kelas untuk fasilitas tipe Truck\n
 * Truck berguna untuk mengirim hasil dagangan
 */
class Truck:public Facility, public TimerObject{
    public:
        /**
         * @brief Konstruktor kelas Truck dengan parameter
         * 
         * @param _x Lokasi X
         * @param _y Lokasi Y
         */
        Truck(int _x, int _y);
        /**
         * @brief Mengembalikan lambang untuk Mixer
         * 
         * @return Lambang yang ditampilkan untuk Mixer 
         */
        std::string render();

    private:

        /**
         * @brief Aktivasi Truck kembali
         * 
         * Fungsi ini akan dipanggil saat Truck bisa digunakan kembali
         */
        void callback();
};
#endif
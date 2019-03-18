/**
 * @file Facility.h
 * @author Back End K3
 * @brief File berisi definisi class Facility
 * @version 0.1
 * @date 2019-03-01
 */
#ifndef FACILITY_H
#define FACILITY_H

#include <Cell/Cell.h>

/**
 * @brief Kelas abstrak turunan Cell
 * @class Facility Facility.h <Cell/Facility.h>
 * 
 * Kelas ini adalah turunan dari class cell yang bertipe fasilitas
 */
class Facility: public Cell{
    public:
        /**
         * @brief Konstruktor kelas Facility
         * 
         * @param _x Lokasi X
         * @param _y Lokasi Y
         */
        Facility(int _x, int _y);
        /**
         * @brief Mengecek apakah Facility dapat digunakan
         * 
         * @return True saat bisa digunakan
         */
        bool isUsable() const;


    protected:
        bool usable;
};

#endif
/**
 * @file Well.h
 * @author Back End K3
 * @brief File definisi kelas Well
 * @version 0.1
 * @date 2019-03-01
 */
#ifndef WELL_H
#define WELL_H

#include <Cell/Facility.h>

/**
 * @brief Kelas Well
 * @class Well Well.h <Cell/Facility/Well.h>
 * 
 * Kelas untuk well yang merupakan salah satu tipe facility
 */
class Well:public Facility{
    public:
        /**
         * @brief Konstruktor objek Well
         * 
         * @param _x Lokasi X
         * @param _y Lokasi Y
         */
        Well(int _x, int _y);
        /**
         * @brief mengembalikan lambang untuk Well
         * 
         * @return lambang yang ditampilkan untuk Well 
         */
        std::string render();
};

#endif
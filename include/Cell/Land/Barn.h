/**
 * @file Barn.h
 * @author Back End K3
 * @brief File berisi definisi kelas Barn
 * @version 0.1
 * @date 2019-03-02
 */

#ifndef BARN_H
#define BARN_H

#include <Cell/Land.h>

/**
 * @brief Kelas riil Barn
 * 
 * Kelas untuk salah satu tipe Land yaitu Barn
 * Tipe Land ini dapat ditinggali binatang yang menghasilkan daging
 */
class Barn:public Land{
    public:
        /**
         * @brief Konstruktor objek Barn
         * 
         * @param _x Lokasi X
         * @param _y Lokasi Y
         */
        Barn(int _x, int _y);

        /**
         * @brief mengembalikan lambang untuk Barn
         * 
         * @return lambang yang ditampilkan untuk Barn
         */
        std::string render();
};

#endif
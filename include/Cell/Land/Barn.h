/**
 * @file Barn.h
 * @author Back End K3
 * @brief File berisi definisi class Barn
 * @version 0.1
 * @date 2019-03-02
 */

#ifndef BARN_H
#define BARN_H

#include <Cell/Land.h>

/**
 * @brief Kelas riil turunan Land
 * @class Barn Barn.h <Cell/Land/Barn.h>
 * 
 * Kelas untuk salah satu tipe Land yaitu Barn\n
 * Tipe Land ini dapat ditinggali hewan yang menghasilkan daging
 */
class Barn:public Land{
    public:
        /**
         * @brief Konstruktor kelas Barn
         * 
         * @param _x Lokasi X
         * @param _y Lokasi Y
         */
        Barn(int _x, int _y);

        /**
         * @brief Mengembalikan lambang untuk Barn
         * 
         * @return Lambang yang ditampilkan untuk Barn
         */
        std::string render();

        short getFgColor();
};

#endif
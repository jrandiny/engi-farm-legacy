/**
 * @file GrassLand.h
 * @author Back End K3
 * @brief File berisi definisi class GrassLand
 * @version 0.1
 * @date 2019-03-02
 */

#ifndef GRASSLAND_H
#define GRASSLAND_H

#include <Cell/Land.h>

/**
 * @brief Kelas riil turunan Land
 * @class GrassLand GrassLand.h <Cell/Land/GrassLand.h>
 * 
 * Kelas untuk salah satu tipe Land yaitu GrassLand\n
 * Tipe Land ini dapat ditinggali hewan yang menghasilkan susu
 */
class GrassLand:public Land{
    public:
        /**
         * @brief Konstruktor kelas GrassLand
         * 
         * @param _x Lokasi X
         * @param _y Lokasi Y
         */
        GrassLand(int _x, int _y);
        /**
         * @brief Mengembalikan lambang untuk GrassLand
         * 
         * @return Lambang yang ditampilkan untuk GrassLand
         */
        std::string render();
};

#endif
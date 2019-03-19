/**
 * @file Coop.h
 * @author Back End K3
 * @brief File berisi definisi class Coop
 * @version 0.1
 * @date 2019-03-02
 */

#ifndef COOP_H
#define COOP_H

#include <Cell/Land.h>

/**
 * @brief Kelas riil turunan Land
 * @class Coop Coop.h <Cell/Land/Coop.h>
 * 
 * Kelas untuk salah satu tipe Land yaitu Coop\n
 * Tipe Land ini dapat ditinggali hewan yang menghasilkan telur
 */
class Coop:public Land{
    public:
        /**
         * @brief Konstruktor kelas Coop
         * 
         * @param _x Lokasi X
         * @param _y Lokasi Y
         */
        Coop(int _x, int _y);
        
        /**
         * @brief Mengembalikan lambang untuk Coop
         * 
         * @return Lambang yang ditampilkan untuk Coop
         */
        std::string render();
};

#endif
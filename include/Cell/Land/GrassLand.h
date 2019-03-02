/**
 * @file GrassLand.h
 * @author Back End K3
 * @brief File berisi definisi kelas GrassLand
 * @version 0.1
 * @date 2019-03-02
 */

#ifndef GRASSLAND_H
#define GRASSLAND_H

#include <Cell/Land.h>

/**
 * @brief Kelas riil Grasland
 * 
 * Kelas untuk salah satu tipe Land yaitu GrassLand
 * Tipe Land ini dapat ditinggali binatang yang menghasilkan susu
 */
class GrassLand:public Land{
    public:
        GrassLand(int _x, int _y);
        std::string render();
};

#endif
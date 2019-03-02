/**
 * @file Coop.h
 * @author Back End K3
 * @brief File berisi definisi kelas Coop
 * @version 0.1
 * @date 2019-03-02
 */

#ifndef COOP_H
#define COOP_H

#include <Cell/Land.h>

/**
 * @brief Kelas riil Coop
 * 
 * Kelas untuk salah satu tipe Land yaitu Coop
 * Tipe Land ini dapat ditinggali binatang yang menghasilkan telur
 */
class Coop:public Land{
    public:
        Coop(int _x, int _y);
        std::string render();
};

#endif
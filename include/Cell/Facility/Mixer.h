/**
 * @file Mixer.h
 * @author Back End K3
 * @brief File berisi definisi class mixer
 * @version 0.1
 * @date 2019-03-01
 */
#ifndef MIXER_H
#define MIXER_H

#include <Cell/Facility.h>

/**
 * @brief Kelas riil turunan Facility
 * @class Mixer Mixer.h <Cell/Facility/Mixer.h>
 * 
 * Kelas ini adalah kelas untuk fasilitas mixer 
 */
class Mixer:public Facility{
    public:
        /**
         * @brief Konstruktor kelas Mixer dengan parameter
         * 
         * @param _x Lokasi X
         * @param _y Lokasi Y
         */
        Mixer(int _x, int _y);
        
        /**
         * @brief Mengembalikan lambang untuk Mixer
         * 
         * @return Lambang yang ditampilkan untuk Mixer 
         */
        std::string render();
};
#endif
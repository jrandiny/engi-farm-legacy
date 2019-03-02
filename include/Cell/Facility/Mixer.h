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
 * @brief Kelas fasilitas Mixer
 * @class Mixer Mixer.h <Cell/Facility/Mixer.h>
 * 
 * Kelas ini adalah kelas untuk fasilitas mixer 
 */
class Mixer:public Facility{
    public:
        Mixer(int _x, int _y);
};
#endif
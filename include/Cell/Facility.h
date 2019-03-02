/**
 * @file Facility.h
 * @author Back End K3
 * @brief File untuk class Facility
 * @version 0.1
 * @date 2019-03-01
 */
#ifndef FACILITY_H
#define FACILITY_H

#include <Cell/Cell.h>

/**
 * @brief Kelas abstrak Facility
 * @class Facility Facility.h <Cell/Facility.h>
 * 
 * Kelas ini adalah turunan dari class cell yang bertipe fasilitas
 */
class Facility: public Cell{
    public:
        Facility(int _x, int _y);
        bool isUsable() const;
    protected:
        bool usable;
};

#endif
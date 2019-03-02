/**
 * @file Cell.h
 * @author Back End K3
 * @brief File berisi definisi kelas Cell
 * @version 0.1
 * @date 2019-03-01 
 */

#ifndef CELL_H
#define CELL_H

#include <Renderable.h>

/**
 * @brief Kelas abstrak Cell
 * @class Cell Cell.h <Cell/Cell.h>
 * 
 * Kelas ini adalah parent dari semua class yang berupa cell
 * Cell adalah satu petak objek di peta yang tidak bergerak
 */
class Cell : public Renderable{
    public:
        /**
         * @brief Konstruktor class Cell
         * 
         * @param _x Lokasi X
         * @param _y Lokasi Y
         */
        Cell(int _x, int _y);

        /**
         * @brief Apakah Cell terisi (tidak dapat dilewati)
         * 
         * @return cell terisi
         */
        bool isOccupied() const;
        int getX() const;
        int getY() const;
    protected:
        const int x;
        const int y;
        bool occupied;
};

#endif
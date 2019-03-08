/**
 * @file Cell.h
 * @author Back End K3
 * @brief File berisi definisi class Cell
 * @version 0.1
 * @date 2019-03-01 
 */

#ifndef CELL_H
#define CELL_H

#include <Renderable.h>

/**
 * @brief Kelas abstrak turunan Renderable
 * @class Cell Cell.h <Cell/Cell.h>
 * 
 * Kelas ini adalah parent dari semua class yang berupa cell\n
 * Cell adalah satu petak objek di peta yang tidak bergerak
 */
class Cell : public Renderable{
    public:
        /**
         * @brief Konstruktor kelas Cell
         * 
         * @param _x Lokasi X
         * @param _y Lokasi Y
         */
        Cell(int _x, int _y);
        
        /**
         * @brief Mengecek apakah Cell terisi
         * 
         * @return Cell terisi atau tidak
         */
        bool isOccupied() const;
        /**
         * @brief Mengembalikan lokasi X
         * 
         * @return Lokasi X 
         */
        int getX() const;
        /**
         * @brief Mengembalikan lokasi Y
         * 
         * @return Lokasi Y
         */
        int getY() const;
    protected:
        const int x;
        const int y;
        bool occupied;
};

#endif
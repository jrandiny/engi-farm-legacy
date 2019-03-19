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
 * Kelas ini adalah parent dari semua class yang berupa Cell\n
 * Cell adalah satu petak objek di peta yang tidak bergerak
 */
class Cell : public Renderable{
    public:
        /**
         * @brief Konstruktor kelas Cell
         * 
         * @param _x Lokasi X
         * @param _y Lokasi Y
         * @param _type type Cell
         */
        Cell(int _x, int _y, int _type);


        /**
         * @brief Mengambil tipe objek
         * 
         * @return Tipe (1 = Barn, 2 = Coop, 3 = GrassLand, 4 = Mixer, 5 = Truck, 6 = Well)
         */
        int getType() const;
        
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

        /**
         * @brief Mengambalikan apakah objek Cell in sama dengan objek this
         * 
         * @param in objek Cell pembanding
         * @return true jika objek Cell in sama dengan objek this
         * @return false jika objek Cell in tidak sama dengan objek this
         */
        bool operator==(Cell& in);

    protected:
        /**
         * @brief Atribut yang menyatakan lokasi X
         */
        const int x;
        /**
         * @brief Atribut yang menyatakan lokasi Y
         */
        const int y;
        /**
         * @brief Atribut tipe Cell 
         * 
         * - 1 = Barn
         * - 2 = Coop
         * - 3 = GrassLand
         * - 4 = Mixer
         * - 5 = Truck
         * - 6 = Well
         */
        const int type;
        /**
         * @brief Aribut yang menyatakan kondisi Cell apakah dapat terisi (tidak dapat dilewati)
         */
        bool occupied;
};

#endif
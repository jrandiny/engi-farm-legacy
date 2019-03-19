/**
 * @file Land.h
 * @author Back End K3
 * @brief File berisi definisi class Land
 * @version 0.1
 * @date 2019-03-01
 */
#ifndef LAND_H
#define LAND_H

#include <Cell/Cell.h>

/**
 * @brief Kelas abstrak turunan Cell
 * @class Land Land.h <Cell/Land.h>
 * 
 * Kelas ini adalah untuk tiap Cell bertipe tanah tempat yang bisa dijalani\n
 * Di dalamnya bisa terdapat grass dan tipe tanah
 */
class Land : public Cell{
    public:
        /**
         * @brief Konstruktor kelas Land
         * 
         * @param _x Lokasi X
         * @param _y Lokasi Y
         * @param _type Tipe tanah (1 = Barn, 2 = Coop, 3 = GrassLand)
         */
        Land(int _x, int _y, CellType _type);

        /**
         * @brief Menempati sebuah Land
         * 
         * Membuat sebuah Land ter-occupy, jika sudah ter-occupy, tidak terjadi apa-apa
         */
        void occupy();
        /**
         * @brief Unoccupy sebuah Land
         * 
         * Membuat sebuah Land jadi tidak ter-occupy, jika sudah tidak ter-occupy, tidak terjadi apa-apa
         */
        void unoccupy();

        /**
         * @brief Apakah mempunyai rumput
         * 
         * Mereturn True saat Land mempunyai rumput, jika tidak False
         * 
         * @return Apakah Land mempunyai rumput 
         */
        bool haveGrass() const;

        /**
         * @brief Menghilangkan rumput
         * 
         * Menghilangkan rumput pada Land, jika sudah tidak ada, tidak terjadi apa-apa
         */
        void removeGrass();

        /**
         * @brief Menanam rumput
         * 
         * Menambahkan rumput pada Land, jika sudah ada, tidak terjadi apa-apa
         */
        void addGrass();

    private:
        bool grass;
};

#endif
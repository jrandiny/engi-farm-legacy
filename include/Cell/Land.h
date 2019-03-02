/**
 * @file Land.h
 * @author Back End K3
 * @brief File berisi definisi kelas Land
 * @version 0.1
 * @date 2019-03-01
 */
#ifndef LAND_H
#define LAND_H

#include <Cell/Cell.h>

/**
 * @brief Kelas Land
 * @class Land Land.h <Cell/Land.h>
 * 
 * Kelas ini adalah untuk tiap Cell bertipe tanah tempat yang bisa dijalani
 * Di dalamnya bisa terdapat grass dan tipe tanah
 * 
 * @var type Tipe tanah (0 = coop, 1 = grassland, 2 = barn)
 */
class Land : public Cell{
    public:
        /**
         * @brief Konstruktor class Land
         * 
         * @param _x Lokasi X
         * @param _y Lokasi Y
         * @param _type Tipe tanah (0 = coop, 1 = grassland, 2 = barn)
         */
        Land(int _x, int _y, int _type);

        /**
         * @brief Mengambil tipe objek
         * 
         * @return Tipe tanah (0 = coop, 1 = grassland, 2 = barn)
         */
        int getType() const;

        /**
         * @brief Menempati sebuah Land
         * 
         * Membuat sebuah Land teroccupy, jika sudah teroccupy, tidak terjadi apa-apa
         */
        void occupy();
        /**
         * @brief Unoccupy sebuah Land
         * 
         * Membuat sebuah Land jadi tidak teroccupy, jika sudah tidak teroccupy, tidak terjadi apa-apa
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
        const int type;
};

#endif
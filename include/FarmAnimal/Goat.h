/**
 * @file Goat.h
 * @author Back End K3
 * @brief File berisi definisi kelas Goat
 * @version 0.1
 * @date 2019-03-01
 */

#ifndef GOAT_H
#define GOAT_H

#include <FarmAnimal/FarmAnimal.h>
#include <Product/FarmProduct/GoatMilk.h>
#include <Product/FarmProduct/GoatMeat.h>

/**
 * @brief Kelas riil Goat
 * @class Goat Goat.h <FarmAnimal/Goat.h>
 * 
 * Kelas ini adalah turunan dari kelas FarmAnimal
 * Goat adalah animal yang menghasilkan GoatMeat dan GoatMilk
 */
class Goat : public FarmAnimal{
    public:
        /**
         * @brief konstruktor objek Goat dengan tipe habitatnya
         * 
         * @param type tipe habitat Goat
         */
        Goat(int type);
        /**
         * @brief mengembalikan suara Goat
         * 
         * @return String suara Goat 
         */
        std::string speak();
        /**
         * @brief mendapatkan produk oleh Goat
         * 
         * @return GoatMilk jika habitat berada di GrassLand
         * @return GoatMeat jika habitat berada di Barn 
         */
        std::shared_ptr<Product> getProduct();
        /**
         * @brief mengembalikan lambang untuk Goat
         * 
         * @return lambang yang ditampilkan untuk Goat 
         */
        std::string render();
};

#endif
/**
 * @file Horse.h
 * @author Back End K3
 * @brief File berisi definisi Kelas Horse
 * @version 0.1
 * @date 2019-03-01
 */

#ifndef HORSE_H
#define HORSE_H

#include <FarmAnimal/FarmAnimal.h>
#include <Product/FarmProduct/HorseMeat.h>

/**
 * @brief Kelas riil Horse
 * @class Horse Horse.h <FarmAnimal/Horse.h>    
 * 
 * Kelas ini adalah turunan dari kelas FarmProduct
 * Horse adalah animal yang dapat menghasilkan HorseMeat
 */
class Horse : public FarmAnimal{
    public:
        /**
         * @brief konstruktor objek Horse
         * 
         */
        Horse();

        /**
         * @brief mengembalikan suara Horse
         * 
         * @return suara Horse 
         */
        std::string speak();
        /**
         * @brief mendapatkan produk oleh Horse
         * 
         * @return HorseMeat
         */
        std::shared_ptr<Product> getProduct();
        /**
         * @brief mengembalikan lambang untuk Horse
         * 
         * @return lambang yang ditampilkan untuk Horse 
         */
        std::string render();
};

#endif
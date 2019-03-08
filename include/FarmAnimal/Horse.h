/**
 * @file Horse.h
 * @author Back End K3
 * @brief File berisi definisi class Horse
 * @version 0.1
 * @date 2019-03-01
 */

#ifndef HORSE_H
#define HORSE_H

#include <FarmAnimal/FarmAnimal.h>
#include <Product/FarmProduct/HorseMeat.h>

/**
 * @brief Kelas riil turunan FarmAnimal
 * @class Horse Horse.h <FarmAnimal/Horse.h>    
 * 
 * Kelas ini adalah turunan dari kelas FarmProduct\n
 * Horse adalah animal yang dapat menghasilkan HorseMeat
 */
class Horse : public FarmAnimal{
    public:
        /**
         * @brief Konstruktor kelas Horse
         * 
         */
        Horse();

        /**
         * @brief Mengembalikan suara Horse
         * 
         * @return Suara Horse 
         */
        std::string speak();
        /**
         * @brief Mendapatkan produk oleh Horse
         * 
         * @return HorseMeat
         */
        std::shared_ptr<Product> getProduct();
        /**
         * @brief Mengembalikan lambang untuk Horse
         * 
         * @return Lambang yang ditampilkan untuk Horse 
         */
        std::string render();
};

#endif
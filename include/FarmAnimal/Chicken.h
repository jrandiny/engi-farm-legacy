/**
 * @file Chicken.h
 * @author Back End K3
 * @brief File berisi definisi class Chicken
 * @version 0.1
 * @date 2019-03-01
 */

#ifndef CHICKEN_H
#define CHICKEN_H

#include <FarmAnimal/FarmAnimal.h>
#include <Product/FarmProduct/ChickenEgg.h>

/**
 * @brief Kelas riil turunan FarmAnimal
 * @class Chicken Chicken.h <FarmAnimal/Chicken.h>
 * 
 * Kelas ini adalah turunan dari kelas FarmAnimal\n
 * Chicken adalah animal yang dapat menghasilkan ChickenEgg
 */
class Chicken : public FarmAnimal{
    public:

        /**
         * @brief Konstruktor kelas Chicken
         * 
         */
        Chicken();
        /**
         * @brief Mengembalikan suara Chicken
         * 
         * @return String suara Chicken
         */
        std::string speak();
        /**
         * @brief Mendapatkan produk oleh Chicken
         * 
         * @return ChickenEgg
         */
        std::shared_ptr<Product> getProduct();
        /**
         * @brief Mengembalikan lambang untuk Chicken
         * 
         * @return Lambang yang ditampilkan untuk Chicken 
         */
        std::string render();
};

#endif
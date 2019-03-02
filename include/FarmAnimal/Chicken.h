/**
 * @file Chicken.h
 * @author Back End K3
 * @brief File berisi definisi Kelas Chicken
 * @version 0.1
 * @date 2019-03-01
 */

#ifndef CHICKEN_H
#define CHICKEN_H

#include <FarmAnimal/FarmAnimal.h>
#include <Product/FarmProduct/ChickenEgg.h>

/**
 * @brief Kelas riil Chicken
 * @class Chicken Chicken.h <FarmAnimal/Chicken.h>
 * 
 * Kelas ini adalah turunan dari kelas FarmAnimal
 * Chicken adalah animal yang dapat menghasilkan ChickenEgg
 */
class Chicken : public FarmAnimal{
    public:

        /**
         * @brief konstruktor objek Chicken
         * 
         */
        Chicken();
        /**
         * @brief mengembalikan suara Chicken
         * 
         * @return String suara Chicken
         */
        std::string speak();
        /**
         * @brief mendapatkan produk oleh Chicken
         * 
         * @return ChickenEgg
         */
        std::shared_ptr<Product> getProduct();
        /**
         * @brief mengembalikan lambang untuk Chicken
         * 
         * @return lambang yang ditampilkan untuk Chicken 
         */
        std::string render();
};

#endif
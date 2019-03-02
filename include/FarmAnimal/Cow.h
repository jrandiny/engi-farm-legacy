/**
 * @file Cow.h
 * @author Back End K3
 * @brief File berisi definisi kelas Cow
 * @version 0.1
 * @date 2019-03-01
 */

#ifndef COW_H
#define COW_H

#include <FarmAnimal/FarmAnimal.h>
#include <Product/FarmProduct/CowMeat.h>
#include <Product/FarmProduct/CowMilk.h>

/**
 * @brief Kelas riil Cow
 * @class Cow Cow.h <FarmAnimal/Cow.h>
 * 
 * Kelas ini adalah turunan dari kelas FarmAnimal
 * Cow adalah object animal yang dapat menghasilkan CowMeat dan CowMilk
 */
class Cow : public FarmAnimal{
    public:

        /**
         * @brief konstruktor objek Cow dengan tipe habitatnya
         * 
         * @param type tipe habitat Goat
         */
        Cow(int type);

        /**
         * @brief mengembalikan suara Cow
         * 
         * @return String suara Cow
         */
        std::string speak();

        /**
         * @brief mendapatkan produk oleh Cow
         * 
         * @return CowMilk jika habitat berada di GrassLand
         * @return CowMeat jika habitat berada di Barn 
         */
        std::shared_ptr<Product> getProduct();
        /**
         * @brief mengembalikan lambang untuk Cow
         * 
         * @return lambang yang ditampilkan untuk Cow 
         */
        std::string render();
};

#endif
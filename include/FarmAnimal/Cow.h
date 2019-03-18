/**
 * @file Cow.h
 * @author Back End K3
 * @brief File berisi definisi class Cow
 * @version 0.1
 * @date 2019-03-01
 */

#ifndef COW_H
#define COW_H

#include <FarmAnimal/FarmAnimal.h>
#include <Product/FarmProduct/CowMeat.h>
#include <Product/FarmProduct/CowMilk.h>

/**
 * @brief Kelas riil turunan FarmAnimal
 * @class Cow Cow.h <FarmAnimal/Cow.h>
 * 
 * Kelas ini adalah turunan dari kelas FarmAnimal\n
 * Cow adalah object animal yang dapat menghasilkan CowMeat dan CowMilk
 */
class Cow : public FarmAnimal{
    public:

        /**
         * @brief Konstruktor kelas Cow dengan paremeter
         * 
         * @param type Tipe habitat Goat
         */
        Cow(int type);

        /**
         * @brief Mengembalikan suara Cow
         * 
         * @return String suara Cow
         */
        std::string speak();

        /**
         * @brief Mendapatkan produk oleh Cow
         * 
         * @return CowMilk jika habitat berada di GrassLand
         * @return CowMeat jika habitat berada di Barn 
         */
        std::shared_ptr<Product> getProduct();
        /**
         * @brief Mengembalikan lambang untuk Cow
         * 
         * @return Lambang yang ditampilkan untuk Cow 
         */
        std::string render();

};

#endif
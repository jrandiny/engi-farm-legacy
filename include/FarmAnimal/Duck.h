/**
 * @file Duck.h
 * @author Back End K3
 * @brief File berisi definisi kelas Duck
 * @version 0.1
 * @date 2019-03-01
 */
#ifndef DUCK_H
#define DUCK_H

/**
 * @brief Kelas riil Duck
 * @class Duck Duck.h <FarmAnimal/Duck.h>
 * 
 * Kelas turunan FarmAnimal
 * Menghasilkan DuckEgg
 */
#include <FarmAnimal/FarmAnimal.h>
#include <Product/FarmProduct/DuckEgg.h>

class Duck : public FarmAnimal{
    public:
        /**
         * @brief konstruktor objek Duck
         * 
         */
        Duck();
        /**
         * @brief mengembalikan suara Duck
         * 
         * @return String suara Duck
         */
        std::string speak();
        /**
         * @brief mendapatkan produk oleh Duck
         * 
         * @return DuckEgg
         */
        std::shared_ptr<Product> getProduct();
        /**
         * @brief mengembalikan lambang untuk Duck
         * 
         * @return lambang yang ditampilkan untuk Duck 
         */
        std::string render();
};

#endif
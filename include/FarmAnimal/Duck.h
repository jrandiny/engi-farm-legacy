/**
 * @file Duck.h
 * @author Back End K3
 * @brief File berisi definisi class Duck
 * @version 0.1
 * @date 2019-03-01
 */
#ifndef DUCK_H
#define DUCK_H

/**
 * @brief Kelas riil turunan FarmAnimal
 * @class Duck Duck.h <FarmAnimal/Duck.h>
 * 
 * Kelas turunan FarmAnimal\n
 * Menghasilkan DuckEgg
 */
#include <FarmAnimal/FarmAnimal.h>
#include <Product/FarmProduct/DuckEgg.h>

class Duck : public FarmAnimal{
    public:
        /**
         * @brief Konstruktor kelas Duck
         * 
         */
        Duck();
        /**
         * @brief Mengembalikan suara Duck
         * 
         * @return String suara Duck
         */
        std::string speak();
        /**
         * @brief Mendapatkan produk oleh Duck
         * 
         * @return DuckEgg
         */
        std::shared_ptr<Product> getProduct();
        /**
         * @brief Mengembalikan lambang untuk Duck
         * 
         * @return Lambang yang ditampilkan untuk Duck 
         */
        std::string render();
};

#endif
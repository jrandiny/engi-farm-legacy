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
#include <FarmAnimal.h>
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
        String speak();
        /**
         * @brief mendapatkan produk oleh Duck
         * 
         * @return DuckEgg
         */
        FarmProduct getProduct();   
};

#endif
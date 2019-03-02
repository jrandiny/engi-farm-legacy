/**
 * @file Rabbit.h
 * @author Back End K3
 * @brief File berisi definisi kelas Rabbit
 * @version 0.1
 * @date 2019-03-01
 */

#ifndef RABBIT_H
#define RABBIT_H

#include <FarmAnimal.h>
#include <Product/FarmProduct/RabbitMeat.h>

/**
 * @brief Kelas riil Rabbit
 * @class Rabbit Rabbit.h <FarmAnimal/Rabbit.h>
 * 
 * Kelas ini adalah turunan dari kelas FarmAnimal
 * Rabbit adalah animal yang dapat menghasilkan RabbitMeat
 */
class Rabbit : public FarmAnimal{
    public:
        /**
         * @brief konstruktor objek Rabbit
         * 
         */
        Rabbit();
        /**
         * @brief mengembalikan suara Rabbit
         * 
         * @return String suara Goat 
         */
        String speak();
        /**
         * @brief mendapatkan produk oleh Rabbit
         * 
         * @return RabbitMeat 
         */
        FarmProduct getProduct();
};

#endif
/**
 * @file Rabbit.h
 * @author Back End K3
 * @brief File berisi definisi kelas Rabbit
 * @version 0.1
 * @date 2019-03-01
 */

#ifndef RABBIT_H
#define RABBIT_H

#include <FarmAnimal/FarmAnimal.h>
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
        std::string speak();
        /**
         * @brief mendapatkan produk oleh Rabbit
         * 
         * @return RabbitMeat 
         */
        std::shared_ptr<Product> getProduct();
        /**
         * @brief mengembalikan lambang untuk Rabbit
         * 
         * @return lambang yang ditampilkan untuk Rabbit 
         */
        std::string render();
};

#endif
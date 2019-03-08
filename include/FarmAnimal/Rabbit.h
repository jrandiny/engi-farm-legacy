/**
 * @file Rabbit.h
 * @author Back End K3
 * @brief File berisi definisi class Rabbit
 * @version 0.1
 * @date 2019-03-01
 */

#ifndef RABBIT_H
#define RABBIT_H

#include <FarmAnimal/FarmAnimal.h>
#include <Product/FarmProduct/RabbitMeat.h>

/**
 * @brief Kelas riil turunan FarmAnimal
 * @class Rabbit Rabbit.h <FarmAnimal/Rabbit.h>
 * 
 * Kelas ini adalah turunan dari kelas FarmAnimal\n
 * Rabbit adalah animal yang dapat menghasilkan RabbitMeat
 */
class Rabbit : public FarmAnimal{
    public:
        /**
         * @brief Konstruktor kelas Rabbit
         * 
         */
        Rabbit();
        /**
         * @brief Mengembalikan suara Rabbit
         * 
         * @return String suara Goat 
         */
        std::string speak();
        /**
         * @brief Mendapatkan produk oleh Rabbit
         * 
         * @return RabbitMeat 
         */
        std::shared_ptr<Product> getProduct();
        /**
         * @brief Mengembalikan lambang untuk Rabbit
         * 
         * @return Lambang yang ditampilkan untuk Rabbit 
         */
        std::string render();
};

#endif
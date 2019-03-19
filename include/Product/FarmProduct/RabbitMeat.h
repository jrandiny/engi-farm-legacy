/**
 * @file RabbitMeat.h
 * @author Back End K3
 * @brief File berisi definisi class RabbitMeat
 * @version 0.1
 * @date 2019-03-01
 */

#ifndef RABBITMEAT_H
#define RABBITMEAT_H

#include <Product/FarmProduct.h>
#include <Player.h>

/**
 * @brief Kelas riil turunan FarmProduct
 * @class RabbitMeat RabbitMeath <Product/FarmProduct/RabbitMeat.h>
 * 
 * Kelas ini adalah turunan dari kelas FarmProduct\n
 * RabbitMeat adalah Product yang dihasilkan dari object animal Rabbit
 */
class RabbitMeat : public FarmProduct{
  public:
    /**
     * @brief Konstruktor kelas RabbitMeat
     * 
     */
    RabbitMeat();

    /**
     * @brief Mengembalikan lambang untuk RabbitMeat
     * 
     * @return Lambang yang ditampilkan untuk RabbitMeat
     */
    std::string render();

};

#endif

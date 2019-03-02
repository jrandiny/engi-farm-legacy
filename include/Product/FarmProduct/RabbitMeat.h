/**
 * @file RabbitMeat.h
 * @author Back End K3
 * @brief file berisi definisi kelas RabbitMeat
 * @version 0.1
 * @date 2019-03-01
 */

#ifndef RABBITMEAT_H
#define RABBITMEAT_H

#include <Product/FarmProduct.h>
#include <Player.h>

/**
 * @brief Kelas riil RabbitMeat
 * @class RabbitMeat RabbitMeath <Product/FarmProduct/RabbitMeat.h>
 * 
 * Kelas ini adalah turunan dari kelas FarmProduct
 * RabbitMeat adalah product yang dihasilkan dari object animal Rabbit
 */
class RabbitMeat : public FarmProduct{
  public:
    /**
     * @brief Construct a new Rabbit Meat object
     * 
     */
    RabbitMeat();

};

#endif

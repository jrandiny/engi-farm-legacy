/**
 * @file Meatza.h
 * @author Back End K3
 * @brief file berisi definisi kelas Meatza
 * @version 0.1
 * @date 2019-03-01
 */

#ifndef MEATZA_H
#define MEATZA_H

#include <Product/SideProduct.h>
#include <Product/FarmProduct/GoatMeat.h>
#include <Product/FarmProduct/HorseMeat.h>
#include <Product/FarmProduct/RabbitMeat.h>
#include <Player.h>

/**
 * @brief Kelas riil Meetza
 * @class Meatza Meatza.h <Product/SideProduct/Meatza.h>
 * 
 * Kelas ini adalah turunan dari kelas SideProduct
 * Meatza dapat dibuat dari GoatMeat, HorseMeat, RabbitMeat dari FarmProduct
 */
class Meatza : public SideProduct{
  public:
    /**
     * @brief constructor object Meatza
     * 
     */
    Meatza();

    /**
     * @brief fungsi getRecipe yang mengembalikan linkedlist product bahan membuat Meatza
     * 
     * @return LinkedList<Product> resep dari Meatza
     */
    LinkedList<Product> getRecipe();

  private:

};

#endif
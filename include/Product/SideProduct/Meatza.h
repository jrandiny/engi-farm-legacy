/**
 * @file Meatza.h
 * @author Back End K3
 * @brief File berisi definisi class Meatza
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
 * @brief Kelas riil turunan SideProduct
 * @class Meatza Meatza.h <Product/SideProduct/Meatza.h>
 * 
 * Kelas ini adalah turunan dari kelas SideProduct\n
 * Meatza dapat dibuat dari GoatMeat, HorseMeat, RabbitMeat dari FarmProduct
 */
class Meatza : public SideProduct{
  public:
    /**
     * @brief Konstruktor kelas Meatza
     * 
     */
    Meatza();

    /**
     * @brief Mengembalikan LinkedList of shared_ptr of Product bahan membuat Meatza
     * 
     * @return LinkedList bahan-bahan untuk membuat Meatza
     */
    LinkedList<std::shared_ptr<Product>> getRecipe();

    /**
     * @brief Mengembalikan lambang untuk Meatza
     * 
     * @return Lambang yang ditampilkan untuk Meatza
     */
    std::string render();

  private:

};

#endif
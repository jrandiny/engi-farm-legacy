/**
 * @file EggBenedict.h
 * @author Back End K3
 * @brief File berisi definisi class EggBenedict
 * @version 0.1
 * @date 2019-03-01
 */

#ifndef EGGBENEDICT_H
#define EGGBENEDICT_H

#include <Product/SideProduct.h>
#include <Product/FarmProduct/DuckEgg.h>
#include <Product/FarmProduct/RabbitMeat.h>
#include <Product/FarmProduct/GoatMilk.h>
#include <Player.h>

/**
 * @brief Kelas riil turunan SideProduct
 * @class EggBenedict EggBenedict.h <Product/SideProduct/EggBenedict.h>
 * 
 * Kelas ini adalah turunan dari kelas SideProduct\n
 * EggBenedict dapat dibuat dari DuckEgg, RabbitMeat, dan GoatMilk dari FarmProduct
 */
class EggBenedict : public SideProduct{
  public:
    /**
     * @brief Konstruktor kelas EggBendict
     * 
     */
    EggBenedict();

    /**
     * @brief Mengembalikan linkedlist product bahan membuat EggBenedict
     * 
     * @return LinkedList bahan-bahan untuk membuat EggBenedict
     */
    LinkedList<std::shared_ptr<Product>> getRecipe();

    /**
     * @brief Mengembalikan lambang untuk EggBenedict
     * 
     * @return Lambang yang ditampilkan untuk EggBenedict
     */
    std::string render();

  private:

};

#endif
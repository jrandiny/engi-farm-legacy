/**
 * @file EggBenedict.h
 * @author Back End K3
 * @brief file berisi definisi kelas EggBenedict
 * @version 0.1
 * @date 2019-03-01
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef EGGBENEDICT_H
#define EGGBENEDICT_H

#include <Product/SideProduct.h>
#include <Product/FarmProduct/DuckEgg.h>
#include <Product/FarmProduct/RabbitMeat.h>
#include <Product/FarmProduct/GoatMilk.h>
#include <Player.h>

/**
 * @brief Kelas riil EggBenedict
 * @class EggBenedict EggBenedict.h <Product/SideProduct/EggBenedict.h>
 * 
 * Kelas ini adalah turunan dari kelas SideProduct
 * EggBenedict dapat dibuat dari DuckEgg, RabbitMeat, dan GoatMilk dari FarmProduct
 */
class EggBenedict : public SideProduct{
  public:
    /**
     * @brief constructor object EggBendict
     * 
     */
    EggBenedict();

    /**
     * @brief fungsi getRecipe yang mengembalikan linkedlist product bahan membuat EggBenedict
     * 
     * @return LinkedList<std::shared_ptr<Product>> resep dari EggBenedict
     */
    LinkedList<std::shared_ptr<Product>> getRecipe();

    /**
     * @brief mengembalikan lambang untuk EggBenedict
     * 
     * @return lambang yang ditampilkan untuk EggBenedict
     */
    std::string render();

  private:

};

#endif
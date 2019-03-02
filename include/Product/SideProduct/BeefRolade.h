/**
 * @file BeefRolade.h
 * @author Back End K3
 * @brief File berisi definisi kelas BeefRolade
 * @version 0.1
 * @date 2019-03-01
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef BEEFROLADE_H
#define BEEFROLADE_H

#include <Product/SideProduct.h>
#include <Product/FarmProduct/CowMeat.h>
#include <Product/FarmProduct/ChickenEgg.h>
#include <Player.h>

/**
 * @brief Kelas riil BeefRolade
 * @class BeefRolade BeefRolade.h <Product/FarmProduct/BeefRolade.h>
 * 
 * Kelas ini adalah turunan dari SideProduct
 * BeefRolade dapat dibuat dari CowMeat dan ChickenEgg dari FarmProduct
 */
class BeefRolade : public SideProduct{
  public:
    /**
     * @brief constructor object BeefRolade
     * 
     */
    BeefRolade();

    /**
     * @brief fungsi getRecipe yang mengembalikan linkedlist product bahan membuat BeefRolade
     * 
     * @return LinkedList<Product> resep dari BeefRolade
     */
    LinkedList<Product> getRecipe();

  private:

};

#endif
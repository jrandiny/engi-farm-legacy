/**
 * @file BeefRolade.h
 * @author Back End K3
 * @brief File berisi definisi class BeefRolade
 * @version 0.1
 * @date 2019-03-01
 */

#ifndef BEEFROLADE_H
#define BEEFROLADE_H

#include <Product/SideProduct.h>
#include <Product/FarmProduct/CowMeat.h>
#include <Product/FarmProduct/ChickenEgg.h>
#include <Player.h>

/**
 * @brief Kelas riil turunan SideProduct
 * @class BeefRolade BeefRolade.h <Product/FarmProduct/BeefRolade.h>
 * 
 * Kelas ini adalah turunan dari SideProduct\n
 * BeefRolade dapat dibuat dari CowMeat dan ChickenEgg dari FarmProduct
 */
class BeefRolade : public SideProduct{
  public:
    /**
     * @brief Konstruktor kelas BeefRolade
     * 
     */
    BeefRolade();

    /**
     * @brief Mengembalikan linkedlist product bahan membuat BeefRolade
     * 
     * @return LinkedList bahan-bahan untuk membuat BeefRolade
     */
    LinkedList<std::shared_ptr<Product>> getRecipe();

    /**
     * @brief Mengembalikan lambang untuk BeefRolade
     * 
     * @return Lambang yang ditampilkan untuk BeefRolade
     */
    std::string render();

  private:

};

#endif
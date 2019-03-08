/**
 * @file ChickenEgg.h
 * @author Back End K3
 * @brief File berisi definisi class ChickenEgg
 * @version 0.1
 * @date 2019-03-01
 */
#ifndef CHICKENEGG_H
#define CHICKENEGG_H

#include <Product/FarmProduct.h>
#include <Player.h>

/**
 * @brief Kelas riil turunan FarmProduct
 * @class ChickenEgg ChickenEgg.h <Product/FarmProduct/ChickenEgg.h>
 * 
 * Kelas ini adalah turunan dari kelas FarmProduct\n
 * ChickenEgg adalah product yang dihasilkan oleh object animal Chicken
 */
class ChickenEgg : public FarmProduct{
  public:
    /**
     * @brief Konstruktor kelas ChickenEgg
     * 
     */
    ChickenEgg();

    /**
     * @brief Mengembalikan lambang untuk ChickenEgg
     * 
     * @return Lambang yang ditampilkan untuk ChickenEgg
     */
    std::string render();

  private:
};

#endif
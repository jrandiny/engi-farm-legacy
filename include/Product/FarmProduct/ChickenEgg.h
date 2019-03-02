/**
 * @file ChickenEgg.h
 * @author Back End K3
 * @brief file berisi definisi kelas ChickenEgg
 * @version 0.1
 * @date 2019-03-01
 */
#ifndef CHICKENEGG_H
#define CHICKENEGG_H

#include <Product/FarmProduct.h>
#include <Player.h>

/**
 * @brief Kelas riil ChickenEgg
 * @class ChickenEgg ChickenEgg.h <Product/FarmProduct/ChickenEgg.h>
 * 
 * Kelas ini adalah turunan dari kelas FarmProduct
 * ChickenEgg adalah product yang dihasilkan oleh object animal Chicken
 */
class ChickenEgg : public FarmProduct{
  public:
    /**
     * @brief constructor object ChickenEgg
     * 
     */
    ChickenEgg();

  private:

};

#endif
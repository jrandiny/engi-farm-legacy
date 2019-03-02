/**
 * @file DuckEgg.h
 * @author Back End K3
 * @brief file berisi definisi kelas DuckEgg
 * @version 0.1
 * @date 2019-03-01
 */

#ifndef DUCKEGG_H
#define DUGGEGG_H

#include <Product/FarmProduct.h>
#include <Player.h>

/**
 * @brief Kelas riil DuckEgg
 * @class DuckEgg DuckEgg.h <Product/FarmProduct/DuckEgg.h>
 * 
 * Kelas ini adalah turuna dari kelas FarmProduct
 * DuckEgg adalah product yang dihasilkan dari object animal Duck
 */
class DuckEgg : public FarmProduct{
  public:
    /**
     * @brief constructor object DuckEgg
     * 
     */
    DuckEgg();

};

#endif
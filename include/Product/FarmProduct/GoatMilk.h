/**
 * @file GoatMilk.h
 * @author Back End K3
 * @brief File definisi class GoatMilk
 * @version 0.1
 * @date 2019-03-01
 */

#ifndef GOATMILK_H
#define GOATMILK_H

#include <Product/FarmProduct.h>
#include <Player.h>

/**
 * @brief Kelas riil turunan FarmProduct
 * @class GoatMilk GoatMilk.h <Product/FarmProduct/GoatMilk.h>
 * 
 * Kelas ini adalah turunan dari kelas FarmProduct
 * GoatMilk adalah product yang dihasilkan dari object animal Goat
 */
class GoatMilk : public FarmProduct{
  public:
    /**
     * @brief Konstruktor kelas GoatMilk
     * 
     */
    GoatMilk();

    /**
     * @brief Mengembalikan lambang untuk GoatMilk
     * 
     * @return Lambang yang ditampilkan untuk GoatMilk
     */
    std::string render();
    
  private:

};

#endif
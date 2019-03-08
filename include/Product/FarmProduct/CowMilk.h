/**
 * @file CowMilk.h
 * @author Back End K3
 * @brief File beisi definisi class CowMilk
 * @version 0.1
 * @date 2019-03-01
 */

#ifndef COWMILK_H
#define COWMILK_H

#include <Product/FarmProduct.h>
#include <Player.h>

/**
 * @brief Kelas riil turunan FarmProduct
 * @class CowMilk CowMilk.h <Product/FarmProduct/CowMilk.h>
 * 
 * Kelas ini adalah turunan dari kelas FarmProduct\n
 * CowMilk adalah product yang dihasilkan dari object animal Cow
 */
class CowMilk : public FarmProduct{
  public:
    /**
     * @brief Konstruktor kelas CowMilk
     * 
     */
    CowMilk();

    /**
     * @brief Mengembalikan lambang untuk CowMilk
     * 
     * @return Lambang yang ditampilkan untuk CowMilk
     */
    std::string render();

};

#endif
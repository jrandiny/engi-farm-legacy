/**
 * @file CowMilk.h
 * @author Back End K3
 * @brief file beisi definisi kelas CowMilk
 * @version 0.1
 * @date 2019-03-01
 */

#ifndef COWMILK_H
#define COWMILK_H

#include <Product/FarmProduct.h>
#include <Player.h>

/**
 * @brief Kelas riil CowMilk
 * @class CowMilk CowMilk.h <Product/FarmProduct/CowMilk.h>
 * 
 * Kelas ini adalah turunan dari kelas FarmProduct
 * CowMilk adalah product yang dihasilkan dari object animal Cow
 */
class CowMilk : public FarmProduct{
  public:
    /**
     * @brief constructor object CowMilk
     * 
     */
    CowMilk();

    /**
     * @brief mengembalikan lambang untuk CowMilk
     * 
     * @return lambang yang ditampilkan untuk CowMilk
     */
    std::string render();

};

#endif
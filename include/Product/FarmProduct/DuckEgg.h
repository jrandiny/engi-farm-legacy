/**
 * @file DuckEgg.h
 * @author Back End K3
 * @brief File berisi definisi class DuckEgg
 * @version 0.1
 * @date 2019-03-01
 */

#ifndef DUCKEGG_H
#define DUGGEGG_H

#include <Product/FarmProduct.h>
#include <Player.h>

/**
 * @brief Kelas riil turunan FarmProduct
 * @class DuckEgg DuckEgg.h <Product/FarmProduct/DuckEgg.h>
 * 
 * Kelas ini adalah turuna dari kelas FarmProduct\n
 * DuckEgg adalah product yang dihasilkan dari object animal Duck
 */
class DuckEgg : public FarmProduct{
  public:
    /**
     * @brief Konstruktor kelas DuckEgg
     * 
     */
    DuckEgg();

    /**
     * @brief Mengembalikan lambang untuk DuckEgg
     * 
     * @return Lambang yang ditampilkan untuk DuckEgg
     */
    std::string render();

};

#endif
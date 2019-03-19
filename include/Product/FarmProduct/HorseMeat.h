/**
 * @file HorseMeat.h
 * @author Back End K3
 * @brief File berisi definsi class HorseMeat
 * @version 0.1
 * @date 2019-03-01
 */

#ifndef HORSEMEAT_H
#define HORSEMEAT_H

#include <Product/FarmProduct.h>
#include <Player.h>

/**
 * @brief Kelas riil turunan FarmProduct
 * @class HorseMeat HorseMeat.h <Product/FarmProduct/HorseMeat.h>
 * 
 * Kelas ini adalah turunan dari kelas HorseMeat\n
 * HorseMeat adalah Product yang dihasilkan dari object animal Horse
 */
class HorseMeat : public FarmProduct{
  public:
    /**
     * @brief Konstruktor kelas HorseMeat
     * 
     */
    HorseMeat();

    /**
     * @brief Mengembalikan lambang untuk HorseMeat
     * 
     * @return Lambang yang ditampilkan untuk HorseMeat
     */
    std::string render();

  private:

};

#endif
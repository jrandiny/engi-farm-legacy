/**
 * @file HorseMeat.h
 * @author Back End K3
 * @brief file berisi definsi kelas HorseMeat
 * @version 0.1
 * @date 2019-03-01
 */

#ifndef HORSEMEAT_H
#define HORSEMEAT_H

#include <Product/FarmProduct.h>
#include <Player.h>

/**
 * @brief Kelas riil HorseMeat
 * @class HorseMeat HorseMeat.h <Product/FarmProduct/HorseMeat.h>
 * 
 * Kelas ini adalah turunan dari kelas HorseMeat
 * HorseMeat adalah product yang dihasilkan dari object animal Horse
 */
class HorseMeat : public FarmProduct{
  public:
    /**
     * @brief connstructor object HorseMeat
     * 
     */
    HorseMeat();

    /**
     * @brief mengembalikan lambang untuk HorseMeat
     * 
     * @return lambang yang ditampilkan untuk HorseMeat
     */
    std::string render();

  private:

};

#endif
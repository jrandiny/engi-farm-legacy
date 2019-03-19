/**
 * @file CowMeat.h
 * @author Back End K3
 * @brief File berisi definisi class CowMeat
 * @version 0.1
 * @date 2019-03-01
 */
#ifndef COWMEAT_H
#define COWMEAT_H

#include <Product/FarmProduct.h>
#include <Player.h>

/**
 * @brief Kelas riil turunan FarmProduct
 * @class CowMeat CowMeat.h <Product/FarmProduct/CowMeat.h>
 * 
 * Kelas ini adalah turunan dari kelas FarmProduct\n
 * CowMeat adalah Product yang dihasilkan dari object animal Cow
 */
class CowMeat : public FarmProduct{
  public:
    /**
     * @brief Konstruktor kelas CowMeat
     * 
     */
    CowMeat();

    /**
     * @brief Mengembalikan lambang untuk CowMeart
     * 
     * @return Lambang yang ditampilkan untuk CowMeart
     */
    std::string render();

};

#endif
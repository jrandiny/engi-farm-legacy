/**
 * @file CowMeat.h
 * @author Back End K3
 * @brief file berisi definisi kelas CowMeat
 * @version 0.1
 * @date 2019-03-01
 */
#ifndef COWMEAT_H
#define COWMEAT_H

#include <Product/FarmProduct.h>
#include <Player.h>

/**
 * @brief Kelas riil CowMeat
 * @class CowMeat CowMeat.h <Product/FarmProduct/CowMeat.h>
 * 
 * Kelas ini adalah turunan dari kelas FarmProduct
 * CowMeat adalah product yang dihasilkan dari object animal Cow
 */
class CowMeat : public FarmProduct{
  public:
    /**
     * @brief constructor object CowMeat
     * 
     */
    CowMeat();

    /**
     * @brief mengembalikan lambang untuk CowMeart
     * 
     * @return lambang yang ditampilkan untuk CowMeart
     */
    std::string render();

};

#endif
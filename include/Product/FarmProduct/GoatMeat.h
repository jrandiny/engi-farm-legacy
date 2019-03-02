/**
 * @file GoatMeat.h
 * @author Back End K3
 * @brief file berisi definisi kelas GoatMeat
 * @version 0.1
 * @date 2019-03-01
 */
#ifndef GOATMEAT_H
#define GOATMEAT_H

#include <Product/FarmProduct.h>
#include <Player.h>

/**
 * @brief Kelas riil GoatMeat
 * @class GoatMeat GoatMeat.h <Product/FarmProduct/GoatMeat.h>
 * 
 * Kelas ini adalah turunan dari kelas FarmProduct
 * GoatMeat adalah product yang dihasilkan dari object animal Goat
 */
class GoatMeat : public FarmProduct{
  public:
    /**
     * @brief constructor object GoatMeat
     * 
     */
    GoatMeat();
    
    /**
     * @brief mengembalikan lambang untuk GoatMeat
     * 
     * @return lambang yang ditampilkan untuk GoatMeat
     */
    std::string render();
};

#endif
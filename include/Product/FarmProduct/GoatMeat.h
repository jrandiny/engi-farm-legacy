/**
 * @file GoatMeat.h
 * @author Back End K3
 * @brief File berisi definisi class GoatMeat
 * @version 0.1
 * @date 2019-03-01
 */
#ifndef GOATMEAT_H
#define GOATMEAT_H

#include <Product/FarmProduct.h>
#include <Player.h>

/**
 * @brief Kelas riil turunan FarmProduct
 * @class GoatMeat GoatMeat.h <Product/FarmProduct/GoatMeat.h>
 * 
 * Kelas ini adalah turunan dari kelas FarmProduct\n
 * GoatMeat adalah product yang dihasilkan dari object animal Goat
 */
class GoatMeat : public FarmProduct{
  public:
    /**
     * @brief Konstruktor kelas GoatMeat
     * 
     */
    GoatMeat();
    
    /**
     * @brief Mengembalikan lambang untuk GoatMeat
     * 
     * @return Lambang yang ditampilkan untuk GoatMeat
     */
    std::string render();
};

#endif
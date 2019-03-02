/**
 * @file FarmAnimal.h
 * @author Back End K3
 * @brief File berisi definisi kelas FarmAnimal
 * @version 0.1
 * @date 2019-03-01
 */

#ifndef FARMANIMAL_H
#define FARMANIMAL_H

#include <Product/FarmProduct.h>
#include <Renderable.h>
#include <Cell/Land.h>
#include <string>

/**
 * @brief Kelas abstrak FarmAnimal
 * @class FarmAnimal FarmAnimal.h <FarmAnimal/FarmAnimal.h>
 * 
 * Kelas ini adalah parent dari semua kelas yang merupakan FarmAnimal
 * FarmAnimal adalah hewan yang dapat menghasilkan product
 */
class FarmAnimal : public Renderable{
    public:
        /**
         * @brief Konstruktor class FarmAnimal
         * 
         * @param time Waktu hingga lapar animal
         */
        FarmAnimal(int time);

        /**
         * @brief Menggerakan posisi secara random
         * 
         */
        void moveRandom();

        /**
         * @brief Fungsi virtual untuk mendapatkan produk binatang
         * 
         * @return FarmProduct Produk dari binatang
         */
        virtual FarmProduct getProduct()=0;

        /**
         * @brief Fungsi virtual untuk bicara hewan
         * 
         */
        virtual void speak()=0;

        /**
         * @brief Mengatur status makan binatang
         * 
         */
        void setEatStatus(bool);

        /**
         * @brief Mengambil status makan binatang
         * 
         * @return Status makan
         */
        bool getEatStatus();

        /**
         * @brief Get the Habitat object
         * 
         * @return Mengambil id habitat
         */
        int getHabitat();
    protected:
        const int timeToHungry;
        int posX,posY;
        bool eatStatus;
        const Land habitat;

};

#endif
/**
 * @file FarmAnimal.h
 * @author Back End K3
 * @brief File berisi definisi kelas FarmAnimal
 * @version 0.1
 * @date 2019-03-01
 */

#ifndef FARMANIMAL_H
#define FARMANIMAL_H

#include <Product/Product.h>
#include <Renderable.h>
#include <memory>

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
        FarmAnimal(int time,int type);

        /**
         * @brief Menggerakan posisi secara random
         * 
         */
        void moveRandom();

        /**
         * @brief Fungsi virtual untuk mendapatkan produk binatang
         * 
         * @return Product Produk dari binatang
         */
        virtual std::shared_ptr<Product> getProduct()=0;

        /**
         * @brief Fungsi virtual untuk bicara hewan
         * 
         */
        virtual std::string speak()=0;

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
        const int habitat;

};

#endif
/**
 * @file FarmAnimal.h
 * @author Back End K3
 * @brief File berisi definisi class FarmAnimal
 * @version 0.1
 * @date 2019-03-01
 */

#ifndef FARMANIMAL_H
#define FARMANIMAL_H

#include <Product/Product.h>
#include <Renderable.h>
#include <memory>
#include <TimerObject.h>

/**
 * @brief Kelas abstrak turunan Renderable dan TimerObject
 * @class FarmAnimal FarmAnimal.h <FarmAnimal/FarmAnimal.h>
 * 
 * Kelas ini adalah parent dari semua kelas yang merupakan FarmAnimal\n
 * FarmAnimal adalah hewan yang dapat menghasilkan product
 */
class FarmAnimal : public Renderable, public TimerObject{
    public:
        /**
         * @brief Konstruktor kelas FarmAnimal
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
         * @return Product produk dari binatang
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
         * @return Status sudah makan
         */
        bool getEatStatus();

        /**
         * @brief Mengatur status kematian binatang
         * 
         */
        void setDeathStatus(bool);

        /**
         * @brief Mengambil status kematian binatang
         * 
         * @return Status binatang mati
         */
        bool getDeathStatus();

        /**
         * @brief Mengembalikan id habitat binatang
         * 
         * @return Mengambil id habitat
         */
        int getHabitat();

        /**
         * @brief Callback untuk kelaparan atau mati
         * 
         * Mengatur status animal kapan lapar dan mati
         */
        void callback();

        /**
         * @brief Mengembalikan posisi X binatang
         * 
         * @return posisi X binatang 
         */
        int getX() const;

        /**
         * @brief Mengembalikan posisi Y binatang
         * 
         * @return posisi Y binatang 
         */
        int getY() const;

    protected:
        const int timeToHungry;
        const int timeToDeath = 5;
        int posX,posY;
        bool eatStatus;
        bool deathStatus;
        const int habitat;

};

#endif
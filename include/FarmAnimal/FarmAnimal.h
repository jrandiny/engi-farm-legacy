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
 * FarmAnimal adalah hewan yang dapat menghasilkan Product
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
         * @brief Fungsi virtual untuk mendapatkan produk hewan
         * 
         * @return Product produk dari hewan
         */
        virtual std::shared_ptr<Product> getProduct()=0;

        /**
         * @brief Fungsi virtual untuk bicara hewan
         * 
         */
        virtual std::string speak()=0;

        /**
         * @brief Mengatur status makan hewan
         * 
         */
        void setEatStatus(bool);

        /**
         * @brief Mengambil status makan hewan
         * 
         * @return Status sudah makan
         */
        bool getEatStatus();

        /**
         * @brief Mengatur status kematian hewan
         * 
         */
        void setDeathStatus(bool);

        /**
         * @brief Mengambil status kematian hewan
         * 
         * @return Status hewan mati
         */
        bool getDeathStatus();

        /**
         * @brief Mengembalikan id habitat hewan
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
         * @brief Mengembalikan posisi X hewan
         * 
         * @return Posisi X hewan 
         */
        int getX() const;

        /**
         * @brief Mengembalikan posisi Y hewan
         * 
         * @return Posisi Y hewan 
         */
        int getY() const;

    protected:
        /**
         * @brief Atribut yang menentukan waktu kelaparan hewan
         */
        const int timeToHungry;

        /**
         * @brief Atribut yang menentukan sisa waktu hewan sebelum mati kelaparan
         */
        const int timeToDeath = 5;

        /**
         * @brief Atribut yang menyatakan lokasi X hewan
         */
        int posX;

        /**
         * @brief Atribut yang menyatakan lokasi Y hewan
         */
        int posY;

        /**
         * @brief Atribut yang menyatakan apakah hewan sudah makan
         */
        bool eatStatus;

        /**
         * @brief Atribut yang menyatakan apakah hewan mati
         */
        bool deathStatus;

        /**
         * @brief Atribut yang menentukan habitat hewan
         */
        const int habitat;

};

#endif
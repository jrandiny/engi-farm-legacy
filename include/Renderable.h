/**
 * @file Renderable.h
 * @author Back End K3
 * @brief File berisi definisi class Renderable
 * @version 0.1
 * @date 2019-03-01 
 */

#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <string>

/**
 * @brief Kelas abstrak dasar Renderable
 * @class Renderable Renderable.h <Renderable.h>
 * 
 * Kelas ini adalah parent dari semua kelas yang ada\n
 * Renderable adalah interface untuk semua object yang dapat dirender ke layar
 */

class Renderable{
    public:
        /**
         * @brief Fungsi pure virtual render()
         * 
         * @return char character object turunannya
         */
        virtual std::string render() = 0;

        /**
         * @brief Fungsi pure virtual yang mengembalikan warna foreground
         * 
         * @return short warna foreground
         */
        virtual short getFgColor();

        /**
         * @brief Fungsi pure virtual yang mengembalikan warna background
         * 
         * @return short warna background
         */
        virtual short getBgColor();
};

#endif
/**
 * @file Renderable.h
 * @author Back End K3
 * @brief File berisi definisi kelas renderable
 * @version 0.1
 * @date 2019-03-01 
 */

#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <string>

/**
 * @brief kelas abstrak Renderable
 * @class Renderable Renderable.h <Renderable.h>
 * 
 * Kelas ini adalah parent dari semua kelas yang ada
 * Renderable adalah interface untuk semua object yang dapat dirender ke layar
 */

class Renderable{
    public:
        /**
         * @brief fungsi pure virtual render()
         * 
         * @return char character object turunannya
         */
        virtual std::string render() = 0;
};

#endif
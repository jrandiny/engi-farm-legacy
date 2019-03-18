/**
 * @file Map.h
 * @author Back End K3
 * @brief File berisi definisi class Map
 * @version 0.1
 * @date 2019-03-18
 */

#ifndef MAP_H
#define MAP_H

#include <vector>
#include <Cell/Cell.h>
#include <Cell/Facility.h>
#include <Cell/Land.h>
#include <memory>

class Map{
    public:
        /**
         * @brief Konstruktor kelas Map dengan parameter
         * 
         * @param width Lebar peta
         * @param height Tinggi peta
         */
        Map(int width, int height);
        
        /**
         * @brief Mengembalikan objek di sekitar
         * 
         * @param x Lokasi x
         * @param y Lokasi y
         * @return Referensi ke Cell
         */
        Cell& getSurrounding(int x, int y) const;

        /**
         * @brief Mengembalikan objek Mixer
         * 
         * @param x Lokasi x
         * @param y Lokasi y
         * @return Referensi ke Mixer
         */
        Mixer& getMixer(int x, int y) const;

        /**
         * @brief Mengembalikan objek Truck
         * 
         * @param x Lokasi x
         * @param y Lokasi y
         * @return Refrensi ke Truck
         */
        Truck& getTruck(int x, int y) const;

        /**
         * @brief Mengembalikan objek Well
         * 
         * @param x Lokasi x
         * @param y Lokasi y
         * @return Refrensi ke Well
         */
        Well& getWell(int x, int y) const;

        /**
         * @brief Mengembalikan objek FarmAnimal
         * 
         * @param x Lokasi x
         * @param y Lokasi y
         * @return Referensi ke FarmAnimal
         */
        FarmAnimal& getFarmAnimal(int x, int y) const;

    private:
        std::vector<std::vector<std::shared_ptr<Cell>>> map;
        std::vector<std::shared_ptr<Land>> land;
        std::vector<std::shared_ptr<Mixer>> mixer;
        std::vector<std::shared_ptr<Truck>> truck;
        std::vector<std::shared_ptr<Well>> well;
        std::vector<std::shared_ptr<FarmAnimal>> farmAnimal;
};


#endif